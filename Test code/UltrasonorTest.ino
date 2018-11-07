
int TriggerPinFront = 5;
int EchoPinFront = 4;
int duration;
long Distance;


void setup() {
  // put your setup code here, to run once:

  pinMode(TriggerPinFront, OUTPUT);
  pinMode(EchoPinFront, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(TriggerPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinFront, LOW);
  duration = pulseIn(EchoPinFront, HIGH);
  Distance = duration * 0.034 / 2;
  Serial.println(Distance);

}
