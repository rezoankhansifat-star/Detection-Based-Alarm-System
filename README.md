
# 🧠 Face Detection Alarm using Arduino and Computer Vision

## 📖 Overview
This project combines **Computer Vision** and **Arduino** to create a smart face detection alarm system.  
Whenever a human face is detected by the laptop or PC webcam, an **alarm (buzzer)** connected to Arduino is automatically triggered.  
The goal of this project is to demonstrate real-time interaction between software (computer vision) and hardware (Arduino).

---

## ⚙️ How It Works
1. The **webcam** continuously captures video frames using **OpenCV** in Python.  
2. Each frame is processed with a **Haar Cascade Classifier** to detect human faces.  
3. If a face is detected, Python sends a signal (`'1'`) to the Arduino via **serial communication (USB)**.  
4. The Arduino receives the signal and turns the **buzzer ON**.  
5. When no face is detected, the signal (`'0'`) is sent, and the buzzer turns **OFF**.

---

## 🧩 Components Used
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino UNO | 1 | Microcontroller board used to control the buzzer |
| Buzzer | 1 | Produces sound when triggered |
| Jumper Wires | As required | For circuit connections |
| USB Cable | 1 | To connect Arduino with laptop |
| Laptop/PC with Webcam | 1 | Used for video processing and face detection |

---

## 🖥️ Software Requirements
- **Python 3.x**
- **OpenCV** (`cv2`)
- **PySerial** (`pip install pyserial`)
- **Arduino IDE**

---

## 🧠 Circuit Diagram
**Connections:**
- Buzzer **positive (+)** → Arduino **Digital Pin 8**  
- Buzzer **negative (-)** → Arduino **GND**

---

## 💻 Python Code (Face Detection)
```python
import cv2
import serial
import time

# Initialize serial communication with Arduino
arduino = serial.Serial('COM3', 9600)  # Replace COM3 with your port
time.sleep(2)

# Load Haar Cascade for face detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Start video capture
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    if len(faces) > 0:
        arduino.write(b'1')  # Send signal to Arduino
        cv2.putText(frame, "FACE DETECTED", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2)
    else:
        arduino.write(b'0')  # No face detected

    # Draw rectangles around detected faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)

    cv2.imshow('Face Detection Alarm', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
arduino.close()
cv2.destroyAllWindows()
```

---

## 🔌 Arduino Code
```cpp
int buzzer = 8;
char data;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == '1') {
      digitalWrite(buzzer, HIGH);  // Turn buzzer ON
    } else if (data == '0') {
      digitalWrite(buzzer, LOW);   // Turn buzzer OFF
    }
  }
}
```

---

## 🎯 Features
- Real-time **face detection** using OpenCV  
- Hardware interaction via **serial communication**  
- Simple and effective demonstration of **AI + IoT**  
- Easily customizable (can be extended to door locks, lights, etc.)

---

## 🧪 Possible Improvements
- Add **motion detection** or **multiple object tracking**  
- Integrate **Telegram or Email alert** when face is detected  
- Use **ESP32** for wireless operation  
- Include **face recognition** to identify specific people  

---

## 🖼️ Demo (Optional)
If you have photos or videos, include them here:  
```
![System Working](demo.gif)
```

---

## 📜 License
This project is open-source and available under the **MIT License**.  
Feel free to modify and share it for educational purposes.

---

## 👨‍💻 Author
**Rezoan Khan**  
📍 Bangladesh  
💡 Passionate about Robotics, AI, and Innovative Tech Projects.
