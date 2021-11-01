const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_RIGHT = 9;
const int POWER_LEFT = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;

void setup() {
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_RIGHT, OUTPUT);
  pinMode(POWER_LEFT, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
}

void reverse(int milliseconds){
  digitalWrite(POWER_RIGHT, HIGH);
  digitalWrite(POWER_LEFT, HIGH);
  digitalWrite(LEFT_BACK, HIGH);
  digitalWrite(RIGHT_BACK, HIGH);
  delay(milliseconds);
}

void forwards(int milliseconds){
  digitalWrite(POWER_RIGHT, HIGH);
  digitalWrite(POWER_LEFT, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(LEFT_BACK, LOW);
  digitalWrite(RIGHT_BACK, LOW);
  delay(milliseconds);
}

void left(int milliseconds){
  analogWrite(POWER_LEFT, 255);
  analogWrite(POWER_RIGHT, 255);
  delay(milliseconds);  
}

void right(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 255);
  delay(milliseconds); 
}

void HARD_RIGHT(int milliseconds){
   analogWrite(POWER_LEFT, 255);
    analogWrite(POWER_RIGHT, 255);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACK, HIGH);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    delay(milliseconds);
  
}

void loop(){
    forwards(2000);
    HARD_RIGHT(750);    
    forwards(2000);
    HARD_RIGHT(750); 
    forwards(2000);
    HARD_RIGHT(750); 
    forwards(4000);
    HARD_RIGHT(750);
    forwards(2000);
    HARD_RIGHT(750);
    forwards(2000);
    HARD_RIGHT(750);
    forwards(2000);
    HARD_RIGHT(1500);
    
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    delay(100000);
}
