
const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_1 = 9;
const int POWER_2 = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;

void setup() {
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEFT_BACK, LOW);
  digitalWrite(RIGHT_BACK, LOW);
  delay(1000);
  forwards(1000);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  delay(1000);
  digitalWrite(LEFT_BACK, HIGH);
  digitalWrite(RIGHT_BACK, HIGH);
  delay(1000);
  //This code makes the rover drive forwards for 1 second, pause then drive back for one second
}

void forwards(int milliseconds){
  digitalWrite(POWER_1, HIGH);
  digitalWrite(POWER_2, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  delay(milliseconds);
}
//This is the forward function
