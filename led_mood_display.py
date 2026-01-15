import time
from mood_detector_template.led_control import setup, set_color, turn_off

# Mood to RGB color mapping
mood_colors = {
    'Angry': (1, 0, 0),      # Red
    'Disgust': (0.5, 0.2, 0),# Brownish
    'Fear': (1, 0, 1),       # Magenta
    'Happy': (0, 1, 0),      # Green
    'Sad': (0, 0, 1),        # Blue
    'Surprise': (1, 1, 0),   # Yellow
    'Neutral': (1, 1, 1)     # White
}

def read_mood():
    try:
        with open("mood.txt", "r") as file:
            return file.read().strip()
    except FileNotFoundError:
        print("mood.txt not found")
        return None

def main():
    setup()
    mood = read_mood()
    if mood in mood_colors:
        r, g, b = mood_colors[mood]
        set_color(r, g, b)
        print(f"Showing color for mood: {mood}")
        time.sleep(10)  # Show the LED color for 10 seconds
        turn_off()
    else:
        print(f"Unknown mood: {mood}")
        turn_off()

if __name__ == "__main__":
    main()
