//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define up 3
#define down 4
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  ana();
}
int a=1,b=0,c=0;
void ana(){
  c=0;
  if(b==0){
    lcd.clear();b=1;
  }
  
  lcd.setCursor(6,0);
  lcd.print("MENU");

  lcd.setCursor(1,1);
  lcd.print(">1-LED SURESI");
}
void sayfa2(int d){
  b=0;
  if(c==0){
    lcd.clear();c=1;
  }
  if(d==2){
    lcd.setCursor(0,0);
  lcd.print(">");
  lcd.setCursor(0,1);
  lcd.print(" ");
  }
  if(d==3){
     lcd.setCursor(0,1);
  lcd.print(">");
  lcd.setCursor(0,0);
  lcd.print(" ");
  }
  lcd.setCursor(1,0);
  lcd.print("2-LED ZAMANI");
 lcd.setCursor(1,1);
  lcd.print("3-LED MIKTARI");
}
void loop()

{
  if(digitalRead(down)==0){
    a--;  
    if(a<=1){
      a=1;
    }
    if(a>=3){
      
      a=3;
    }
  
  while(digitalRead(down)==0);
  }
    if(digitalRead(up)==0){
    a++;  
    if(a<=1){
      a=1;
    }
    if(a>=3){
      a=3;
    }
  
  while(digitalRead(up)==0);
  }
  if(a==1){
    ana();
  }
  else if(a==2){
    
    sayfa2(a);
  }
  else if(a==3){
   
    sayfa2(a);
  }
}
