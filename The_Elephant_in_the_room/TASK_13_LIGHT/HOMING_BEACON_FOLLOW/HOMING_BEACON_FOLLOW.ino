int sensorLeft = A7;    
int sensorForward = A6;
int sensorRight = A2;
const int RIGHT_FORWARD = 7;
const int RIGHT_BACK = 8;
const int POWER_RIGHT = 9;
const int POWER_LEFT = 10;
const int LEFT_FORWARD = 11;
const int LEFT_BACK = 12;


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  pinMode(POWER_RIGHT, OUTPUT);
  pinMode(POWER_LEFT, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
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
  analogWrite(POWER_RIGHT, 155);
  delay(milliseconds);  
}

void right(int milliseconds){
  analogWrite(POWER_RIGHT, 255);
  analogWrite(POWER_LEFT, 155);
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
    delay(milliseconds);digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }
  else{
    //left(500);
    ///forwards(500);
  }
 
}
  else{
    //left(500);
    ///forwards(500);
  }
 
}
  else{
    //left(500);
    ///forwards(500);
  }
 
}
  else{
    //left(500);
    ///forwards(500);
  }
 
}
  else{
    //left(500);
    ///forwards(500);
  }
 
}
}

void STOP(){
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(RIGHT_BACK, LOW);
    digitalWrite(LEFT_BACK, LOW);
    digitalWrite(RIGHT_FORWARD, LOW);
}

void loop() {
  // read the value from the sensor:
  sensorForward = analogRead(sensorForward);
  Serial.print("sensorForward");
  Serial.println(sensorForward);

  // ------------------------------------------------------ //

  if ((sensorForward) <=110 and (sensorForward) >70){
    //forwards(0);
  }
  else if ((sensorForward) < 70){
    STOP();
    //exit(0);
  }
  else{
    //left(500);
    ///forwards(500);
  }
 
}
