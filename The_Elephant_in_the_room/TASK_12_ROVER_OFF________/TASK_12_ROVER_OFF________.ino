#include <NewPing.h>
  
#define TRIGGER_PIN 4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define DOWN_TRIGGER_PIN 13 // Trigger pin for downward on the rover 
#define DOWN_ECHO_PIN  17 // Echo pin for downward on the rover 
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
  
NewPing sonar(DOWN_TRIGGER_PIN, DOWN_ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int LEFT_FEEDBACK = 2;
const int RIGHT_FEEDBACK = 3;

volatile int leftcounter = 0;
volatile int rightcounter = 0;

const int ULTRA_TRIG = 4;
const int ULTRA_ECHO = 5;
const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_RIGHT = 9;
const int POWER_LEFT = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;

void setup() {

  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_RIGHT, OUTPUT);
  pinMode(POWER_LEFT, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  sonar.ping_cm();

}

void reverse(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 215);
  digitalWrite(LEFT_BACK, HIGH);
  digitalWrite(RIGHT_BACK, HIGH);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  delay(milliseconds);
  //this makes the rover move bacwards
}

void forwards(int milliseconds){
  analogWrite(POWER_RIGHT, 155);
  analogWrite(POWER_LEFT, 115);
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

void STOP(){
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
    //this makes the rover stop
}

      void LeftMotorISR(){
    leftcounter++;
  }

    void RightMotorISR(){
    rightcounter++;
  }

  void loop(){
    delay(50);
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm());
    Serial.println("cm");

    forwards (0); //this makes it drive forward until the conditions below are met
    
    if (sonar.ping_cm() >14){
      Serial.println("object detected");  
      STOP();
      leftcounter = 0;
      delay(1000);
      reverse(0);
      delay(500);
      // if the rover detects the floor is more than 14cm away, it stops and reverses
      
      Serial.print("Left Counter");
      Serial.println(leftcounter);
    
      Serial.print("Right Counter");
      Serial.println(rightcounter);
      //the left counter is reset in the previous code and this sets it up properly
      if (leftcounter >= 44){
        STOP(); 
        delay(500);
        Serial.print("stopped"); 
        exit(0);
        //when the left counter has reached 44, which is 10cm, it stops
    }
    else{
      Serial.println("driving");
      //this prints driving to check the code is working
    }
    
  }
  }
