
unsigned long prevtime1= millis();
unsigned long prevtime2= millis();
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);

}

long time1=500;
long time2=2000;
bool ledstate=0;
int degisken0=0;
int degisken1=1;
bool deger=0;
int arr[2]={0,255};
void loop() {
if(digitalRead(2)==LOW){
  deger=1;
  }
  
if(deger==1) {
  
  unsigned long current_time=millis();
  Serial.println(current_time);

  if(current_time-prevtime1>time1){

    ledstate=!ledstate;
    digitalWrite(4,ledstate);

    prevtime1=current_time;
    
    }


if(current_time-prevtime2>time2){
analogWrite(3,arr[degisken1]);
analogWrite(5,arr[degisken0]);

 int gecici = degisken0;
 degisken0 = degisken1;
 degisken1 = gecici;

    prevtime2=current_time;
    
    }
  }
}
