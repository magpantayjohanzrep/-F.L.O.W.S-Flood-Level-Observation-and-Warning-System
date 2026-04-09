#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h> 

#define rxPin 2
#define txPin 3
#define trigPin 5
#define echoPin 4
#define buzzer 8  

LiquidCrystal_I2C lcd(0x27,20,4); 

int waterLevel = A3;
int red = 13;
int yellow = 12;
int green = 11;

SoftwareSerial sim800L(rxPin,txPin); 

Servo myservo;

long duration;
int distance;

int servoClosed = 10;
int servoOpen = 100;
int currentPos = servoClosed;

bool isCritical = false;

unsigned long resetStartTime = 0;
bool resetPending = false;

void setup()
{
  lcd.init();
  lcd.backlight(); 

  // Fixed header
  lcd.setCursor(0,0);
  lcd.print("FLOOD MONITORING  ");

  myservo.attach(10); 
  myservo.write(servoClosed);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(waterLevel, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  sim800L.begin(9600);
}

void moveServo(int targetPos)
{
  if(!myservo.attached()) myservo.attach(10);

  if(currentPos < targetPos)
  {
    for(int pos = currentPos; pos <= targetPos; pos++)
    {
      myservo.write(pos);
      delay(5);
    }
  }
  else
  {
    for(int pos = currentPos; pos >= targetPos; pos--)
    {
      myservo.write(pos);
      delay(5);
    }
  }

  currentPos = targetPos;
}

int readUltrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000);
  if(duration == 0) return 999;
  return duration * 0.034 / 2;
}

void loop()
{
  int levelValue = analogRead(waterLevel);
  Serial.print("Water Level: ");
  Serial.println(levelValue);

  // Fixed header
  lcd.setCursor(0,0);
  lcd.print("FLOOD MONITORING  "); // always same

  // NO WATER
  if (!isCritical && levelValue <= 0)
  {
    lcd.setCursor(0,1);
    lcd.print("SYSTEM NORMAL       ");

    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

    moveServo(servoClosed);
    noTone(buzzer);
  }
  // LOW
  else if (!isCritical && levelValue > 200 && levelValue < 350)
  {
    lcd.setCursor(0,1);
    lcd.print("WATER DETECTED      ");

    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

    moveServo(servoClosed);
    noTone(buzzer);
  }
  // MEDIUM
  else if (!isCritical && levelValue >= 350 && levelValue < 400)
  {
    lcd.setCursor(0,1);
    lcd.print("WATER RISING        ");

    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);

    moveServo(servoClosed);
    noTone(buzzer);
  }
  // CRITICAL
  else if (levelValue >= 405 && !isCritical)
  {
    isCritical = true;
    resetPending = false;

    lcd.setCursor(0,1);
    lcd.print("WATER CRITICAL        ");

    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

    moveServo(servoOpen);
    myservo.detach();

    send_sms();
  }

  // Ultrasonic + buzzer
  if(isCritical)
  {
    distance = readUltrasonic();
    Serial.print("Distance: ");
    Serial.println(distance);

    if(distance <= 20)
      tone(buzzer, 1000);
    else
      noTone(buzzer);
  }

  // RESET with 5-second delay
  if(isCritical && levelValue <= 400)
  {
    if(!resetPending)
    {
      resetPending = true;
      resetStartTime = millis();
    }
    else if(millis() - resetStartTime >= 5000)
    {
      isCritical = false;
      resetPending = false;

      myservo.attach(10); 
      moveServo(servoClosed);

      noTone(buzzer);

      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(red, LOW);

      lcd.setCursor(0,1);
      lcd.print("SYSTEM NORMAL       ");
    }
  }
  else
  {
    resetPending = false;
  }
}

void send_sms()
{
  sim800L.println("AT");
  waitForResponse();

  sim800L.println("AT+CMGF=1");
  waitForResponse();

  sim800L.println("AT+CMGS=\"+639273852473\"");
  delay(1000);

  sim800L.print("FLOOD ALERT! Evacuate immediately.");
  delay(500);

  sim800L.write(26);
  delay(1500);
}

void waitForResponse()
{
  delay(500);
  while(sim800L.available())
  {
    Serial.write(sim800L.read());
  }
}