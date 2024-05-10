
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(9, 8); // RX, TX

void setup() {
pinMode(3,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  bluetooth.begin(9600);
  Serial.begin(9600);
}
int a=0;
void loop() { // run over and over

 a+=1;
    bluetooth.println(a);
delay(100);
}
