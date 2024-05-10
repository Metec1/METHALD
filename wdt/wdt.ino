#include<avr/wdt.h>
void setup() {
   Serial.begin(9600);
   Serial.println("Ard basliyor");
   wdt_disable(); //Disable WDT
   delay(3000);
   wdt_enable(WDTO_2S); //Enable WDT with a timeout of 2 seconds
   Serial.println("WDT Enabled");
}
void loop() {
   for(int i = 0; i<5; i++)
   {
      Serial.println("Looping");
      delay(1000);
      wdt_reset(); //Reset the watchdog
   }
   while(1); //Watchdog timer should get triggered here
}
