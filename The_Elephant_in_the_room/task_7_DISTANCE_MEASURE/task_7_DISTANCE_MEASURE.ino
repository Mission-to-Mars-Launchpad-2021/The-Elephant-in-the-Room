const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_RIGHT = 9;
const int POWER_LEFT = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;

void forwards(int milliseconds){
  digitalWrite(POWER_RIGHT, HIGH);
  digitalWrite(POWER_LEFT, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  delay(milliseconds);
}
//THIS MAKES THE ROVER MOVE

void left(int milliseconds){
  analogWrite(POWER_LEFT, 255);
  analogWrite(POWER_RIGHT, 50);
  delay(milliseconds); 
  //THIS MAKES THE ROVER MOVE LEFT 
}

void right(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 50);
  delay(milliseconds); 
  //THIS MAKES THE ROVER MOVE RIGHT
}

const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter = 0;
volatile int rightcounter = 0;


void setup(){
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_RIGHT, OUTPUT);
  pinMode(POWER_LEFT, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
}

void loop(){
  
  Serial.print("Left Counter");
  Serial.println(leftcounter);

  Serial.print("Right Counter");
  Serial.println(rightcounter);

  analogWrite(POWER_RIGHT, 200);
  analogWrite(POWER_LEFT, 255);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(RIGHT_FORWARD, HIGH);
  
  if (leftcounter >= 915){
    STOP();
    Serial.print("stopped");
    exit(0);
    // THIS MAKES THE ROVER TRAVEL FOR 2 METERS THEN STOP
  }
  }

void STOP(){
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  //THIS MAKES THE ROVER STOP MOVING
}



void LeftMotorISR(){
  leftcounter++;
  // THIS COUNTS THE AMOUNT OF TIMES THE LEFT WHEEL OF THE ROVER TURNS
}

void RightMotorISR(){
  rightcounter++;
  // THIS COUNTS THE AMOUNT OF TIMES THE RIGHT WHEEL OF THE ROVER TURNS
}
