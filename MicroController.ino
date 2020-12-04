void keyPress(int butState, char key);
void commandPress(int butState, int command);

#include <Keyboard.h>

const int SIZE = 13;
const int LEFT = 216;
const int RIGHT = 215;
const int UP = 218;
const int DOWN = 217;
const int ENTER = 176;
int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, A0, A1};
int buttonState[SIZE];

void setup() {
  for (int i = 0; i < SIZE; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {

  for (int i = 0; i < SIZE; i++) {
    buttonState[i] = digitalRead(buttonPins[i]);
  }
  keyPress(buttonState[0], 'a');
  keyPress(buttonState[1], 'b');
  keyPress(buttonState[2], 'x');
  keyPress(buttonState[3], 'y');
  keyPress(buttonState[4], 'l');
  keyPress(buttonState[5], 'r');
  keyPress(buttonState[6], 'q');
  keyPress(buttonState[7], 'z');
  commandPress(buttonState[8], LEFT);
  commandPress(buttonState[9], RIGHT);
  commandPress(buttonState[10], UP);
  commandPress(buttonState[11], DOWN);
  commandPress(buttonState[12], ENTER);
  Serial.println(buttonState[12]);
}

void keyPress(int butState, char key) {
  if (butState == HIGH) {
    Keyboard.press(key);
    delay(10);
  }
  else {
    Keyboard.release(key);
  }
}

void commandPress(int butState, int command) {
  if (command != ENTER) {
    if (butState == LOW) {
      Keyboard.press(command);
      delay(10);
    }
    else {
      Keyboard.release(command);
    }
  }
  else {
    if (butState == HIGH) {
      Keyboard.press(command);
      delay(10);
    }
    else {
      Keyboard.release(command);
    }
  }
}
