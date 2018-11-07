#include <RedBot.h>

RedBotSensor LeftSensor = RedBotSensor(A0);
RedBotSensor RightSensor = RedBotSensor(A1);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("left: ");
Serial.print(LeftSensor.read());
Serial.print("right: ");
Serial.println(RightSensor.read());

delay(10);


}
