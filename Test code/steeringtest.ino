

void setup() {
  // put your setup code here, to run once:

pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10,LOW);
digitalWrite(11,HIGH);
delay(400);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(2000);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
delay(400);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(2000);

}
