const int bPin = 2;
const int modeLedPin = 11;
const int mainLedPin = 3;
const int potPin = A0;
const int SIZE = 9;
bool pushed = false;
int potValue;
int mode = 0;
int bState = 0;
int lastbState = 0;
int ControllerButtonPins[] = {4, 5, 6, 7, 8, 9, 10, 12, A1};
int ControllerButtonStates[SIZE];

void setup() {
  for (int i = 0; i < SIZE; i++) {
    pinMode(ControllerButtonPins[i], INPUT_PULLUP);
  }
  pinMode(bPin, INPUT_PULLUP);
  pinMode(modeLedPin, OUTPUT);
  pinMode(mainLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < SIZE; i++) {
    ControllerButtonStates[i] = digitalRead(ControllerButtonPins[i]);
  }
  bState = digitalRead(bPin);
  potValue = map(analogRead(potPin), 0, 1024, 0 , 255);

  if (bState == LOW && lastbState == HIGH) {
    if (mode >= 3)
      mode = 0;
    else
      mode++;
  }
  lastbState = bState;


  if (mode == 0) {
    analogWrite(modeLedPin, 255);
    analogWrite(mainLedPin, 255);
  }

  else if (mode == 1) {
    analogWrite(modeLedPin, potValue);
    analogWrite(mainLedPin, potValue);
  }

  else if (mode == 2) {
    digitalWrite(modeLedPin, HIGH);
    digitalWrite(mainLedPin, HIGH);
    for (int i = 0; i < SIZE; i++) {
      if (ControllerButtonStates[i] == HIGH) {
        pushed = true;
      }
    }
    if (pushed) {
      digitalWrite(mainLedPin, LOW);
      delay(90);
      digitalWrite(modeLedPin, HIGH);
      digitalWrite(mainLedPin, HIGH);
      pushed = false;
    }
  }

  else {
    digitalWrite(modeLedPin, LOW);
    digitalWrite(mainLedPin, LOW);
  }

  Serial.print("Mode: ");
  Serial.print(mode);
  Serial.print("  ButtonState: ");
  Serial.print(bState);
  Serial.print("  potValue: ");
  Serial.print(potValue);
  Serial.print("   buttonRead: ");
  Serial.println(pushed);

}
