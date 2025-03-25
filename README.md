# Accident Prevention in U-Turns using Arduino & Ultrasonic Sensors 🚦 

## 📌 Overview
This project aims to **reduce accidents at U-turns** caused by blind spots in roads. It uses **ultrasonic sensors** to detect vehicles, controls **traffic light modules**, and triggers a **buzzer alert** when an object is too close. 

### ⚡ Features:
✅ Detects vehicle presence using **ultrasonic sensors**  
✅ **Traffic signals** change based on object distance:  
   - 🟢 Green: Safe distance  
   - 🟡 Yellow: Approaching U-turn  
   - 🔴 Red: Too close (Alert mode)  
✅ 🚨 **Buzzer sounds when a vehicle is too close**  
✅ **Real-time data** is displayed via Serial Monitor  

---

## 🛠️ Components Required
- **Arduino Uno**  
- **2x Ultrasonic Sensors (HC-SR04)**  
- **2x Miniature Traffic Light LED Modules (5V)**  
- **Buzzer**  
- **Jumper wires & Breadboard**  

---

## 🔌 Circuit Connections
| Component | Pin |
|-----------|----|
| **Ultrasonic Sensor 1** | Trig → 6, Echo → 8 |
| **Ultrasonic Sensor 2** | Trig → 7, Echo → 9 |
| **Traffic Light 1 (Left)** | Red → 10, Yellow → 11, Green → 12 |
| **Traffic Light 2 (Right)** | Red → 13, Yellow → A1, Green → A2 |
| **Buzzer** | A3 |

---

## 🏗️ Working Principle
1. **Ultrasonic sensors** measure distance of vehicles near the U-turn.  
2. The **right sensor controls the left traffic light**, and the **left sensor controls the right traffic light** (to alert opposite vehicles).  
3. Traffic signal changes based on detected distance:
   - **>20 cm** → 🟢 Green (Safe)  
   - **10-20 cm** → 🟡 Yellow (Caution)  
   - **<10 cm** → 🔴 Red (Danger) + 🚨 Buzzer ON  
4. If **either sensor detects a vehicle too close**, the **buzzer activates**.  

---

## How to Run

1.Connect components as per the wiring table.

2.Upload the code to the Arduino Uno.

3.Open Serial Monitor to see real-time distance values.

4.Place an object near the sensors to test traffic light changes and buzzer alerts.

## Project Images

![WhatsApp Image 2025-03-25 at 22 47 31_0b6de7db](https://github.com/user-attachments/assets/dc604dbf-d616-4fd6-8cdb-643a2142b363)

## 📌 Applications
✔ Traffic management at U-turns
✔ Accident prevention in blind spots
✔ Smart road safety systems
