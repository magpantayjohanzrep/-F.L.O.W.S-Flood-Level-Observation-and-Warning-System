<h1 align="center">🌊 F.L.O.W.S - Flood Level Observation and Warning System</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Project-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
  <img src="https://img.shields.io/badge/Field-Embedded%20Systems-orange?style=for-the-badge">
</p>

<p align="justify">
  <strong>📍F.L.O.W.S</strong> (Flood Level Observation and Warning System) is designed to detect rising water levels and provide early warnings through SMS notifications, visual indicators, and sound alerts. It helps reduce risks in flood-prone areas by enabling timely response.
</p>

![final project](https://github.com/magpantayjohanzrep/-F.L.O.W.S-Flood-Level-Observation-and-Warning-System/blob/4bf7a27e85fa88b2f49703b006f22ccccf7a76d3/docs/project%20photos/flows%20pic.png)

# 📖 Overview

Flooding is a major environmental hazard that can cause severe damage to communities, especially in low-lying areas. Many incidents worsen due to the lack of early warning systems.
F.L.O.W.S (Flood Level Observation and Warning System) is a smart solution that detects rising water levels and automatically triggers alerts and protective mechanisms. It integrates sensors, automation, and GSM communication to provide fast and reliable flood warnings.

# ✨ Key Features
- 🌊 Real-time water level monitoring
- 🚧 Automatic flood barrier activation
- 📩 SMS alert system (via GSM module)
- 🔊 Buzzer alarm for immediate warning
- 🚦 LED indicators for visual status
- 📟 LCD display for live system updates
- 🔋 Battery-powered for reliability during outages
- 🧩 System Architecture

![block diagram](https://github.com/magpantayjohanzrep/-F.L.O.W.S-Flood-Level-Observation-and-Warning-System/blob/3edf9a5d16e1400e818b2f281e302be74011f153/docs/project%20photos/mermaid-diagram.png)


# 🛠️ Components
# 🔹 Inputs
- 💧 Water Level Sensor
- 📡 Ultrasonic Sensor (HC-SR04)

# 🔹 Controller
- 🧠 Arduino Microcontroller
- 📶 SIM800L GSM Module

# 🔹 Outputs
- 🚧 Servo Motor (Barrier Control)
- 🔊 Piezo Buzzer
- 🚦 LED Traffic Light Module
- 📟 LCD Display (16x4)
- 📩 SMS Notification

# 🧱 Materials
- 🏠 Cardboard (House Model & Flood Barrier)
- 🔌 Breadboard
- 🔗 Jumper Wires
- 🔋 Power Supply / Battery
- 🪣 Water Container (Testing Setup)



# ⚙️ How It Works

- The system continuously monitors water levels using a water level sensor.

- Once the water reaches a critical threshold, the system activates.
  
- The servo motor raises the flood barrier (attached to a cardboard structure).

- The ultrasonic sensor detects and confirms the barrier movement.
  
# Simultaneously:
- 🔊 Buzzer sounds an alarm
- 🚦 LED indicators activate
- 📟 LCD displays warning status
- 📩 GSM module sends SMS alerts


# ⚡ All responses happen in real-time to ensure immediate warning and protection.


![system](https://github.com/magpantayjohanzrep/-F.L.O.W.S-Flood-Level-Observation-and-Warning-System/blob/a52edbaa6ddd533ad373c0ea27c449fe6e6499ea/docs/project%20photos/mermaid-diagram%20(1).png)


# 🧪 Testing & Demonstration

https://github.com/user-attachments/assets/9e64af5f-9287-4457-8dfd-c01a5e3b0c15

- Simulated rising water using a controlled container
- Verified automatic barrier response
  
# 📩 Confirmed SMS delivery via SIM800L module
![sms](https://github.com/magpantayjohanzrep/-F.L.O.W.S-Flood-Level-Observation-and-Warning-System/blob/e96e907ce708e40cb39fba4b56d4eb5c6473150c/docs/project%20photos/sms.jpg)

- Tested buzzer and LED alerts for accuracy

# 🚀 Future Improvements
- 📡 IoT integration (mobile app monitoring)
- 🌐 Cloud-based data logging
- 🔋 Solar-powered system
- 📊 Real-time dashboard visualization
