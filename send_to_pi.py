import serial
import time

# Adjust COM port or use '/dev/ttyUSB0' or '/dev/ttyACM0' on Linux/Raspberry Pi
arduino = serial.Serial(port='COM7', baudrate=9600, timeout=1)

def send_mood_to_arduino(mood):
    arduino.write(f"{mood}\n".encode())

# Example usage
moods = ["happy", "sad", "angry", "neutral", "surprise"]

for mood in moods:
    send_mood_to_arduino(mood)
    print(f"Sent mood: {mood}")
    time.sleep(2)
