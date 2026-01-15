/* Smart Plant & Soil Monitoring (with I2C LCD, TM1637, Ultrasonic, Relay, Soil sensor)
   Components & pins:
   - Soil sensor AO -> A0
   - Relay IN       -> D7
   - TM1637 CLK,DIO -> D2, D3
   - I2C LCD SDA,SCL-> A4, A5 (I2C address 0x27 typical)
   - Ultrasonic TRIG/ECHO -> D4, D5
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>

// ===== PIN DEFINITIONS =====
#define SOIL_PIN A0
#define RELAY_PIN 7
#define TM1637_CLK 2
#define TM1637_DIO 3
#define ULTRASONIC_TRIG 4
#define ULTRASONIC_ECHO 5

// ===== OBJECTS =====
LiquidCrystal_I2C lcd(0x27, 16, 2);  // change to 0x3F if your module uses that address
TM1637Display display(TM1637_CLK, TM1637_DIO);

// ===== SETTINGS =====
const int dryThreshold = 30; // moisture % below which pump turns ON
const unsigned long loopDelay = 1000; // ms

void setup() {
  // Pins
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // ensure pump OFF initially

  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  digitalWrite(ULTRASONIC_TRIG, LOW);

  // Displays
  lcd.init();
  lcd.backlight();
  display.setBrightness(7); // 0..7

  // Startup message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMART PLANT SYS");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

int readSoilPercent() {
  int raw = analogRead(SOIL_PIN); // 0..1023 (wet->low or high depending sensor)
  // Many cheap soil sensors output lower value for wet (0) and higher for dry (1023).
  // If your sensor is reversed, swap map endpoints.
  int percent = map(raw, 1023, 0, 0, 100); // maps raw to 0..100 where 0 = dry, 100 = wet
  if (percent < 0) percent = 0;
  if (percent > 100) percent = 100;
  return percent;
}

long readUltrasonicDistanceCm() {
  // Send trigger pulse
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);

  // Read echo (timeout 30000 us => ~5 meters)
  unsigned long duration = pulseIn(ULTRASONIC_ECHO, HIGH, 30000UL);

  if (duration == 0) {
    // no echo (out of range)
    return -1;
  } else {
    // Sound speed: 343 m/s => distance(cm) = duration(us) / 58
    long distanceCm = duration / 58;
    return distanceCm;
  }
}

void showOnTM1637(int value) {
  // TM1637 has 4 digits. Display value with no leading zeros for aesthetics.
  if (value < 0) {
    // show dashes for error
    display.showNumberDecEx(0, 0b01000000, true, 4, 0); // not necessary, but keep simple fallback
  } else {
    display.showNumberDec(value, false, 3, 1); // show up to 3 digits starting at pos 1 (to center) 
    // If you prefer left aligned: display.showNumberDec(value);
  }
}

void loop() {
  int moisture = readSoilPercent();
  long distance = readUltrasonicDistanceCm();

  // Pump control
  if (moisture < dryThreshold) {
    digitalWrite(RELAY_PIN, HIGH); // Pump ON (depends on relay module active HIGH)
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Pump OFF
  }

  // LCD line 1: Moisture
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  if (moisture < 10) lcd.print(" "); // tidy spacing
  lcd.print(moisture);
  lcd.print("%  "); // trailing spaces to clear previous content

  // LCD line 2: Pump status + distance
  lcd.setCursor(0, 1);
  if (moisture < dryThreshold) {
    lcd.print("PUMP:ON ");
  } else {
    lcd.print("PUMP:OFF");
  }

  // Display distance as " D:xxcm" - ensure we don't overflow 16 chars
  lcd.print(" ");
  if (distance == -1) {
    lcd.print("D:---cm   "); // out of range or no echo
  } else {
    // Keep it compact
    lcd.print("D:");
    if (distance < 10) lcd.print(" ");
    lcd.print(distance);
    lcd.print("cm  ");
  }

  // 7-seg display: show moisture percent (0..100)
  // We show 3 digits (e.g., 045), leaving one digit blank for nicer look.
  showOnTM1637(moisture);

  delay(loopDelay);
}
