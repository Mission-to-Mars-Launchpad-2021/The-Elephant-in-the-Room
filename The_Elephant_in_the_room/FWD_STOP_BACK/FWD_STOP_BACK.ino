void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
  delay(10000);
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
  
}

//digitalWrite(NUM, HIGH/LOW);
  
//delay(1000);
