void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
int pwm = 0;
void loop() {
  if (Serial.available()>0) {
    pwm = Serial.parseInt();
    if (pwm >= 0 && pwm <= 255) {
      analogWrite(3,pwm);
      analogWrite(5,0);
      pwm = Serial.read();
Serial.println(pwm);

    }





  }

}
