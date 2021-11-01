
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

void STOP(){
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
     //this makes the rover stop
}

  void loop(){
    // GOALS:
    // when object is detected:
    // Stop > Delay for about 2 sec
    // Turn 90 Degrees LEFT not hitting obstacle
    // Forward -> stop
    delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
    
    if (sonar.ping_cm() < 16 and sonar.ping_cm() > 0){
      Serial.println("object detected");  
      HARD_LEFT(1800);
      // if the wall is between 16 and 0 cm away, then turn left. Unless, move forwards
    }
    else{
      forwards(0);
      Serial.println("driving");
    }
  }

    
 
 
