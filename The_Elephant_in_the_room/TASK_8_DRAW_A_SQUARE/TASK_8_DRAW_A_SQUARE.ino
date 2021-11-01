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
  digitalWrite(  forwards(1500);
  STOP();
  delay(500);
  spin360();
  forwards(1500);
  delay(500);
  HARD_LEFT(730);LEFT_BACK, HIGH);
  digitalWrite(RIGHT_BACK, HIGH);
  delay(milliseconds);
  //this makes the rover move backwards
}

void forwards(int milliseconds){
  digitalWrite(POWER_RIGHT, HIGH);
  digitalWrite(POWER_LEFT, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(LEFT_BACK, LOW);
  digitalWrite(RIGHT_BACK, LOW);
  delay(milliseconds);
    //this makes the rover move
}

void left(int milliseconds){
  analogWrite(POWER_LEFT, 255);
  analogWrite(POWER_RIGHT, 255);
  delay(milliseconds); 
    //this makes the rover move left 
}

void right(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 255);
  delay(milliseconds); 
    //this makes the rover move right
}

void HARD_RIGHT(int milliseconds){
   analogWrite(POWER_LEFT, 255);
    analogWrite(POWER_RIGHT, 255);
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACK, HIGH);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    delay(milliseconds);
      //this makes the rover move right sharply by turning one motor to full power forwards and the other to full power backwards
  
}

void loop(){
  // this is where the square starts
    forwards(2000);
    HARD_RIGHT(1000);    
    forwards(2000);
    HARD_RIGHT(1000); 
    forwards(2000);
    HARD_RIGHT(1000); 
    forwards(2000);
    HARD_RIGHT(1000);
    // this is when the square finishes
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    // this turns off the rover
    exit(0);
}


// Commented by: Beanie, head of commenting
