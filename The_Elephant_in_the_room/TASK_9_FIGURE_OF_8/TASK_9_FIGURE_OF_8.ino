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
  //this makes the rover move backwards
}

void forwards(int milliseconds){
  analogWrite(POWER_RIGHT, 215);
  analogWrite(POWER_LEFT, 255);
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
    //this makes the rover move right sharply by turning one motor on fully and one go backwards fully
  
}
void HARD_LEFT(int milliseconds){
    analogWrite(POWER_LEFT, 255);
    analogWrite(POWER_RIGHT, 255);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, HIGH);
    digitalWrite(RIGHT_FORWARD, HIGH);
    delay(milliseconds);
    //this makes the rover move left sharply by turning one motor on fully and one go backwards fully
}


void loop(){
  //this is where the figure of eight starts
    forwards(1500);
    HARD_RIGHT(700);    
    forwards(1500);
    HARD_RIGHT(725); 
    forwards(1500);
    HARD_RIGHT(725);
    forwards(1500);
    HARD_LEFT(800);
    forwards(1500);
    HARD_LEFT(800);
    forwards(1500);
    HARD_LEFT(800);
    forwards(1500);
    HARD_LEFT(800);
    forwards(1300);
    HARD_RIGHT(750);
    //this is where the figure of eight stops
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    exit(0);
}
