/*
  Jarmaggedøn - RANDOM CV MOD 
      Møffenzeef Mødular
        Røss Fish 2017
  http://moffenzeefmodular.com
         CC-BY-NC-SA

         RC Lowpass on pin 4 output: 

                 2k        1k (current limiting)
        Pin 4 --\/\/\/---\/\/\/--OUT
                  |
                  |
                  _ + 
                  _  4.7uf 
                  |
                  |
                 GND

Adjust the values of lowRange and highRange to taste
*/

#include <avr/pgmspace.h>
#include <elapsedMillis.h>

elapsedMillis randomClock; 
int randomClockDuration = 0; 
int var = 0; 
int potRaw = 0;
int CVraw = 0; 
int math = 0; 
int lowRange = 0;
int highRange = 0;

void setup() {
}

void loop() {

  lowRange = 2000; // The slowest speed the random voltage is generated at, measured in miliseconds
  highRange = 1;  // The fastest speed the random voltage is generated at, measured in miliseconds

  potRaw = analogRead(A1);
  CVraw = analogRead(A3);

  math = potRaw + CVraw;
  math = max(math, 0);
  math = min(math, 1023);
  
  randomClockDuration = map(math, 0, 1023, lowRange, highRange); // 

  if (randomClock >= randomClockDuration){
  var = random(255); // write a random voltage to the LED
  randomClock = 0; // Reset the timer 
  }

  analogWrite(0, var);
  analogWrite(1, var);  
}

