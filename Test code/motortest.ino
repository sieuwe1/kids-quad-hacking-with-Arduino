

void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT); 


}

void loop() {
  // put your main code here, to run repeatedly:

for(int x = 0; x < 90; x++){
analogWrite(3,x);
delay(10);

}

delay(1000);

for(int x = 90; x > 0; x--){
analogWrite(3,x);
delay(10);
}

delay(1000);
}
