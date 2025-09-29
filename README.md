# Smart Parking System (Arduino + IR Sensors + LCD)

This project demonstrates a simple **smart parking system** using Arduino, IR sensors, and an I2C LCD.
Each parking place has **two IR sensors**: one for **entry** and one for **exit**. The system tracks available spaces and displays them on an LCD.

---

## 📌 Features

* Supports **2 parking places (A and B)**.
* Each place has an **entry** and **exit sensor**.
* Shows real-time parking availability on a **16x2 I2C LCD**.
* Easy to expand for more places (using arrays).

---

## 🛠️ Hardware Required

* Arduino Uno / Nano / Mega
* IR obstacle sensors (x4)
* I2C LCD 16x2
* Breadboard + jumper wires

---

## ⚡ Wiring

| Component      | Arduino Pin  |
| -------------- | ------------ |
| A Entry Sensor | D8           |
| A Exit Sensor  | D9           |
| B Entry Sensor | D10          |
| B Exit Sensor  | D11          |
| LCD (SDA, SCL) | A4, A5 (Uno) |

---

## 🚀 How It Works

1. When a car passes the **entry sensor**, the available slots decrease.
2. When a car passes the **exit sensor**, the available slots increase.
3. LCD updates in real-time:

```
A: 0/1
B: 1/1
```

---

## 📂 Files

* `smart_parking.ino` → Arduino source code
* `README.md` → Project documentation

---

## 📸 Future Improvements

* Add **more parking places** (using arrays).
* Connect to **mobile app via Bluetooth/WiFi**.
* Log data to **cloud / database** for analytics.

---

👨‍💻 Author: *Zamanbek Azil*
📅 Year: 2025
