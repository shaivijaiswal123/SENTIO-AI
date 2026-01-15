# led_control.py
import RPi.GPIO as GPIO
import time

# Define GPIO pins
RED_PIN = 17
GREEN_PIN = 27
BLUE_PIN = 22

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(RED_PIN, GPIO.OUT)
    GPIO.setup(GREEN_PIN, GPIO.OUT)
    GPIO.setup(BLUE_PIN, GPIO.OUT)

def set_color(r, g, b):
    # For common cathode, HIGH turns LED on
    GPIO.output(RED_PIN, GPIO.HIGH if r else GPIO.LOW)
    GPIO.output(GREEN_PIN, GPIO.HIGH if g else GPIO.LOW)
    GPIO.output(BLUE_PIN, GPIO.HIGH if b else GPIO.LOW)

def turn_off():
    GPIO.output(RED_PIN, GPIO.LOW)
    GPIO.output(GREEN_PIN, GPIO.LOW)
    GPIO.output(BLUE_PIN, GPIO.LOW)

def cleanup():
    GPIO.cleanup()
