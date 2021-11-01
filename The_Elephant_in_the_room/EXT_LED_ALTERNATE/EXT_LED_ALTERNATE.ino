

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);
}

// led 1 ON = led 2 = OFF
// led 1 OFF = led 2 = ON
