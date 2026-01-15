# SENTIO-AI 
### AI-Powered Emotion-Aware IoT Ambience System
SENTIO-AI  is an AI-powered IoT system that detects human emotions in real time using CNN-based facial analysis and dynamically adapts lighting and sound ambience. It creates a closed-loop, emotion-aware environment using affordable hardware and psychology-backed mood regulation.

---

## 📄 Research Paper
This project is supported by a detailed research paper published in an IEEE journal covering system design, 
psychological mapping, hardware-software integration, and experimental evaluation.

🔗 **Paper:** [IoT-Based Mood Sensing Ambience Creator](.[/research/IoT_Mood_Sensing_Ambience_Creator.pdf](https://www.researchgate.net/publication/397083994_IoT_-_based_Mood_Sensing_Ambience_Creator))

---


## 🚀 Overview
Human emotions significantly influence mental well-being, productivity, and daily experiences. However, most smart ambience and home automation systems remain static, manual, and emotionally unaware.

**AURA-SYNC** bridges this gap by creating a **closed-loop emotion-aware environment**. It uses real-time facial emotion recognition powered by a CNN model and automatically adjusts ambient lighting and sound using IoT hardware. The system is designed to be **affordable, scalable, and student-friendly**, making emotional intelligence accessible in smart environments.

---

## 🎯 Problem Statement
Current smart ambience systems:
- Require manual user control
- Cannot sense or adapt to human emotions
- Are expensive and inaccessible for students and small developers

There is a need for a **real-time, automated, emotion-aware ambience system** that responds intelligently to the user’s psychological state.

---

## 💡 Proposed Solution
SENTIO-AI automatically:
1. Captures facial expressions using a webcam
2. Detects emotions using a CNN trained on the FER-2013 dataset
3. Communicates detected mood to an Arduino Uno via serial communication
4. Adapts RGB lighting and ambient sound in real time
5. Uses psychology-backed emotion-to-ambience mapping to guide users toward a calmer and more positive emotional state

---

## 🧠 Key Features
- Real-time facial emotion recognition
- CNN-based deep learning model (FER-2013)
- Emotion-responsive RGB lighting using Arduino
- Voice-controlled ambience via “Aura” Assistant
- Psychology-backed mood regulation logic
- Low-cost and easy-to-deploy prototype
- Real-time mood logging and synchronization

---

## 🏗️ System Architecture
The system consists of:
- **Emotion Detection Module** (OpenCV + CNN)
- **Serial Communication Module** (Python ↔ Arduino)
- **IoT Control Module** (RGB LED via PWM)
- **Voice Assistant Module** (Aura)
- **Mood Logging System**

---

## 🛠️ Technologies Used

### AI & Machine Learning
- Convolutional Neural Network (CNN)
- TensorFlow / Keras
- FER-2013 Dataset

### IoT & Hardware
- Arduino Uno
- Common Cathode RGB LED
- Serial Communication (USB)

### Software & Libraries
- Python
- OpenCV
- NumPy
- pySerial
- SpeechRecognition
- pyttsx3
- pywhatkit
- VLC Media Player

---

## 🎨 Emotion-to-Ambience Mapping

| Detected Emotion | Lighting Effect | Sound Ambience |
|------------------|----------------|----------------|
| Happy | Warm neutral light | Uplifting ambient music |
| Sad / Fatigued | Cool bright light | Energetic background music |
| Angry | Soft warm light | Slow instrumental |
| Fear / Anxious | Balanced neutral light | Lo-fi / calm piano |
| Surprise | Low-intensity warm light | Nature sounds |

🧠 *Mappings are based on psychological and neuroscientific studies on lighting and sound effects on mood.*

---

## 📊 Results & Performance

- **Model Accuracy:** 71.2% (FER-2013 dataset)
- **Precision:** 69.8%
- **Recall:** 70.5%
- **F1-Score:** 70.1%
- **Real-Time Success Rate:** ~80%
- **LED Response Time:** < 1 second

✔ High-intensity emotions (Happy, Angry, Sad) were detected more accurately  
⚠ Performance decreases under low-light conditions or rapid facial movements

---

## ⚠️ Limitations
- Optimized for single-user scenarios
- Reduced accuracy in poor lighting
- Possible dataset bias
- Limited contextual awareness beyond facial expressions

---

## 🔮 Future Scope
- Multi-user emotion aggregation
- Privacy-friendly sensors (thermal/environmental)
- Personalized ambience learning per user
- Integration with smart home ecosystems
- Applications in healthcare, education, and corporate wellness

---


