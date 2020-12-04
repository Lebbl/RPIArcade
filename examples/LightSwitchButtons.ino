/*
  LightSwitchButtons
  Has 2 buttons and 2 LEDs. When one button is pressed, the light assigned to that button is turned on while the other is turned off.
  ground to 10K resistor and #2 pin to button to 5v, ground to 560 resistor to red led to #13 pin, #3 pin to button to ground, ground to 560 resistor to green led to #12 pin
  Written by Levi Brown #200427809
  CS207 Lab 3
  29 September 2020
*/

// constants used to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int gButtonPin = 3;   // the number of the pushbutton that controles the green LED
const int gLedPin = 12;     // the number of the green LED pin

// variables:
int buttonState = 0;         // variable for reading the pushbutton status
int gButtonState = 0;        // variable for reading the green pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  //initialize the green LED pin as output
  pinMode(gLedPin, OUTPUT);
  //initialize the green pushbutton pin as input with a pullup resistor
  pinMode(gButtonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the 2 pushbutton values:
  buttonState = digitalRead(buttonPin);
  gButtonState = digitalRead(gButtonPin);

  // check if the red pushbutton is pressed. If it is, the buttonState is high:
  if (buttonState == HIGH) {
    // turn red LED on:
    digitalWrite(ledPin, HIGH);
    // turn green LED off:
    digitalWrite(gLedPin, LOW);
  }
  // check if the green pushbutton is pressed. If it is, the buttonState is LOW:
  if (gButtonState == LOW) {
    // turn RED off:
    digitalWrite(ledPin,  LOW);
    // turn green LED on
    digitalWrite(gLedPin, HIGH);
  }
  // check if the green AND red pushbutton is pressed. If it is, the buttonState is high and the gButtonsState is LOW:
  if (gButtonState == LOW && buttonState == HIGH) {
    // flicker the lights
    digitalWrite(ledPin,  HIGH);
    digitalWrite(gLedPin, HIGH);
    delay(15);
    digitalWrite(ledPin,  LOW);
    digitalWrite(gLedPin, LOW);
    delay(15);
  }
}
