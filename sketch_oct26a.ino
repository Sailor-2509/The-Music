
/*
  CASIO STYLE MINI KEYBOARD
  Board: Arduino Nano
  12 Push Buttons + Passive Buzzer + Potentiometer

  Buzzer positive (+) -> D8
  Buzzer negative (-) -> GND

  Buttons:
  Key 1  -> D2
  Key 2  -> D3
  Key 3  -> D4
  Key 4  -> D5
  Key 5  -> D6
  Key 6  -> D7
  Key 7  -> D9
  Key 8  -> D10
  Key 9  -> D11
  Key 10 -> D12
  Key 11 -> D13
  Key 12 -> A0

  Other side of every button -> GND

  Potentiometer middle pin -> A2
  Potentiometer outer pins -> 5V and GND
*/

const int buzzerPin = 8;
const int potPin = A2;

// Button pins
const int keyPins[12] = {
  2, 3, 4, 5, 6, 7,
  9, 10, 11, 12, 13, A0
};

// Musical notes from C4 to B4
const int frequencies[12] = {
  262, 277, 294, 311, 330, 349,
  370, 392, 415, 440, 466, 494
};

void setup() {
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < 12; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // Read the potentiometer
  int potValue = analogRead(potPin);

  // Adjust note duration using the potentiometer
  int noteDuration = map(potValue, 0, 1023, 100, 500);

  bool keyPressed = false;

  // Check all 12 keys
  for (int i = 0; i < 12; i++) {
    if (digitalRead(keyPins[i]) == LOW) {
      tone(buzzerPin, frequencies[i]);
      keyPressed = true;
      break;
    }
  }

  // Stop sound when no key is pressed
  if (!keyPressed) {
    noTone(buzzerPin);
  }
}
