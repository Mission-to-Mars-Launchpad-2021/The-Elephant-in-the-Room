#include <NewPing.h>
  
#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

const int ULTRA_TRIG = 4;
const int ULTRA_ECHO = 5;
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
  Serial.begin(115200);
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
}

void forwards(int milliseconds){
  analogWrite(POWER_RIGHT, 155);
  analogWrite(POWER_LEFT, 115);
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
void HARD_LEFT(int milliseconds){
    analogWrite(POWER_LEFT, 255);
    analogWrite(POWER_RIGHT, 255);
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, HIGH);
    digitalWrite(RIGHT_FORWARD, HIGH);
    delay(milliseconds);
}

void STOP(){
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void spin360(){
  HARD_LEFT(2900);
  
}

void loop(){
     //Serial.print("Ping: ");
     //Serial.print(sonar.ping_cm());
     //Serial.println("cm");
     forwards(1500);
     STOP();
     delay(500);
     //spin360();
     delay(500);
     HARD_LEFT(250);
     delay(500);
     forwards(1000);
     STOP();
     delay(500);
     //spin360();
     STOP();
     delay(500);
     HARD_RIGHT(600);
     delay(500);
     forwards(2000);
     STOP();
     delay(500);
     //spin360();
     STOP();
     delay(500);
     HARD_RIGHT(600);
     forwards(2000);
     delay(500);
     //spin360();
     delay(500);
     HARD_RIGHT(1000);
     forwards(2000);
     delay(500);
     //spin360();
     delay(500);
     HARD_RIGHT(900);
     forwards(800);
     delay(500);
     HARD_RIGHT(800);
     forwards(1000);
     delay(500);
     spin360();
     delay(2000);
     STOP();
     exit(0);
        
        }
