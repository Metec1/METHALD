void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
int x,y,z,t;
void loop() {
  // put your main code here, to run repeatedly:
int gelen=analogRead(A0);
Serial.println(gelen);
delay(100);
 if(gelen>=0 &&gelen<=255){
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
}
 if(gelen>=256 &&gelen<=500){
  digitalWrite(9,1);
    digitalWrite(8,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
}
 if(gelen>=501 &&gelen<=750){
  digitalWrite(10,1);
    digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(11,0);
}
 if(gelen>=751){
  digitalWrite(11,1);
    digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
}
}
