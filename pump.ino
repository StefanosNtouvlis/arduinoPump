const int buttonPin = 2;   // Pin connected to the button
const int pumpPin = 9;     // Pin connected to the MOSFET gate
bool pumpState = false;    // Tracks whether the pump is on or off

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button pin with internal pull-up resistor
  pinMode(pumpPin, OUTPUT);         // Pump control pin as output
  digitalWrite(pumpPin, LOW);       // Ensure the pump is off initially
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Button is pressed
    pumpState = !pumpState;            // Toggle the pump state
    digitalWrite(pumpPin, pumpState ? HIGH : LOW); // Control the pump
    delay(200);                        // Simple debounce (wait 200ms)
  }
}
