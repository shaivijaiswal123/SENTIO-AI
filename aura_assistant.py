import speech_recognition as sr
import pyttsx3
import webbrowser

engine = pyttsx3.init()
engine.setProperty('rate', 150)

def speak(text):
    print("Aura:", text)
    engine.say(text)
    engine.runAndWait()

def listen():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening for command...")
        audio = r.listen(source)
    try:
        command = r.recognize_google(audio).lower()
        print("You said:", command)
        return command
    except sr.UnknownValueError:
        return ""
    except sr.RequestError:
        speak("Sorry, I'm having trouble connecting.")
        return ""

def play_youtube(query):
    speak(f"Playing {query} on YouTube.")
    webbrowser.open(f"https://www.youtube.com/results?search_query={query}+music")

def handle_command(command):
    if "stop" in command:
        speak("Stopping all sounds.")
        # Add your stop sound logic here (e.g., stop music playback)
    elif "play happy playlist" in command or "play music" in command:
        play_youtube("happy mood music")
    elif "say something nice" in command:
        speak("You are capable, strong, and full of light. Everything will be okay.")
    elif "play something on youtube" in command:
        play_youtube("uplifting video")
    else:
        speak("Sorry, I didn't get that.")

def wake_word():
    while True:
        command = listen()
        if "hey aura" in command:
            speak("Yes, how can I help?")
            handle_command(listen())

if __name__ == "__main__":
    wake_word()
