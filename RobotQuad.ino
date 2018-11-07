
#include <RedBot.h>



//declare Hbridge pins
int HBridge1 = 10;
int HBridge2 = 11;

//declare motor PWM pin
int MotorPower = 3;

//declare ultrasonic sensors
int TriggerPinFront = 5;
int EchoPinFront = 4;
int duration;
long Distance;

int minDistance = 30;


//declare line sensor
RedBotSensor LeftSensor = RedBotSensor(A0);
RedBotSensor RightSensor = RedBotSensor(A1);

//declare top Speed
int TopSpeed = 100;

//declare steering system variables
RedBotSensor SteerSensor = RedBotSensor(A2);
int SteeredValue = 0;


void setup() {

  //declare modes
  pinMode(TriggerPinFront, OUTPUT);
  pinMode(EchoPinFront, INPUT);

  pinMode(MotorPower, OUTPUT);

  pinMode(HBridge1 , OUTPUT);
  pinMode(HBridge2 , OUTPUT);

  //start Serial
  Serial.begin(115200);
  Serial.println("Start");

}

void loop() {

  Serial.println(FrontSensorDistance() );
 //CheckForObstacle();

  analogWrite(MotorPower, TopSpeed);



  if (LeftSensor.read() > 100 ) {

    adjust_directionRight();

  }

  else if (RightSensor.read() > 100) {

    adjust_directionLeft();

  }


}


void CheckForObstacle() {

  if (FrontSensorDistance()  < minDistance && FrontSensorDistance()  > 2) {

    Serial.println("STOP");

    while (FrontSensorDistance()  < minDistance )
    {
      analogWrite(MotorPower, 0);
    }
    delay(4000);

    for (int x = 0; x < TopSpeed; x++) {
      analogWrite(MotorPower, x);
      //Moet nog een safety check tussen!!!
      delay(100);
    }
  }
}

void adjust_directionLeft() {

  Serial.println("links");

  while (RightSensor.read() > 100)
  {
    
    if (SteeredValue <= 200) {

Serial.println("sturen naar links"); 
      
      digitalWrite(HBridge1, HIGH);
      digitalWrite(HBridge2, LOW);
      SteeredValue += 1;

    }
    else {

Serial.println("einde"); 
      
      digitalWrite(HBridge2, LOW);
      digitalWrite(HBridge1, LOW);

    }
  }

  while (SteerSensor.read() < 100) {

Serial.println("terug sturen"); 

    digitalWrite(HBridge2, HIGH);
    digitalWrite(HBridge1, LOW);

  }

Serial.println("terug terug sturen"); 
  digitalWrite(HBridge2, LOW);
  digitalWrite(HBridge1, HIGH);
  delay(100);

  digitalWrite(HBridge2, LOW);
  digitalWrite(HBridge1, LOW);

  SteeredValue = 0;

}

void adjust_directionRight() {

  Serial.println("rechts");

  while (LeftSensor.read() > 100)
  {

    
    if (SteeredValue <= 200) {

      Serial.println("sturen naar rechts"); 
      
      digitalWrite(HBridge2, HIGH);
      digitalWrite(HBridge1, LOW);
      SteeredValue += 1;

    }
    else {

      Serial.println("einde");
      digitalWrite(HBridge2, LOW);
      digitalWrite(HBridge1, LOW);

    }
  }
  while (SteerSensor.read() < 100) {

Serial.println("terug sturem");

    digitalWrite(HBridge2, LOW);
    digitalWrite(HBridge1, HIGH);

  }

Serial.println("terug terug sturen"); 
  digitalWrite(HBridge2, HIGH);
  digitalWrite(HBridge1, LOW);
  delay(100);

  digitalWrite(HBridge2, LOW);
  digitalWrite(HBridge1, LOW);

  SteeredValue = 0;

}


/*
  void adjust_directionLeft() {

  Serial.println("links");
  Serial.println(LeftSensor.read());

  while (RightSensor.read() > 100)
  {
    if(SteeredValue <= 350){
    digitalWrite(HBridge1, HIGH);
    digitalWrite(HBridge2, LOW);
    SteeredValue += 1;

    }
    else{
    digitalWrite(HBridge2, LOW);
    digitalWrite(HBridge1, LOW);

  }

  }

  digitalWrite(HBridge2, HIGH);
  digitalWrite(HBridge1, LOW);
  delay(SteeredValue);
  SteeredValue = 0;
  return;

  }


  //steer right
  void adjust_directionRight() {

  Serial.println("rechts");
  Serial.println(RightSensor.read());

  while (LeftSensor.read() > 100)
  {

  if(SteeredValue <= 350){
    digitalWrite(HBridge2, HIGH);
    digitalWrite(HBridge1, LOW);
    SteeredValue += 1;
    Serial.print(SteeredValue);
    Serial.println("sturen naa rechts");
  }
  else{
    digitalWrite(HBridge2, LOW);
    digitalWrite(HBridge1, LOW);

  }

  }


  Serial.print("final steered value ");
  Serial.println(SteeredValue);


  digitalWrite(HBridge2, LOW);
  digitalWrite(HBridge1, HIGH);
  delay(SteeredValue);

  digitalWrite(HBridge2, LOW);
  digitalWrite(HBridge1, LOW);

  SteeredValue = 0;



  }
*/


long FrontSensorDistance() {
  digitalWrite(TriggerPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinFront, LOW);
  duration = pulseIn(EchoPinFront, HIGH);
  Distance = duration * 0.034 / 2;

  return Distance;
}














