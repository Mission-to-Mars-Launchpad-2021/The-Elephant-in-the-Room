
const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_RIGHT = 9;
const int POWER_LEFT = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_RIGHT, OUTPUT);
  pinMode(POWER_LEFT, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
  
}
void loop(){
  forwards(10000);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  exit(0);
}

void forwards(int milliseconds){
  digitalWrite(POWER_RIGHT, HIGH);
  digitalWrite(POWER_LEFT, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  delay(milliseconds);
    //this function makes the rover go forwards
}

void left(int milliseconds){
  analogWrite(POWER_LEFT, 255);
  analogWrite(POWER_RIGHT, 50);
  delay(milliseconds);  
    //this function makes the rover go left
}

void right(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 50);
  delay(milliseconds); 
  //this function makes the rover go right
}
