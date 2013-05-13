/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led13 = 13;
int led12 = 12;
int led11 = 11;
//delay
int ledDelay = 50;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.  
  
  
  pinMode(led13, OUTPUT);   
  pinMode(led12, OUTPUT); 
  pinMode(led11, OUTPUT);     
  
  
}

// the loop routine runs over and over again forever:
void loop() {
  //WRITING TO FIRST LED
  digitalWrite(led13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led13, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);               // wait for a second
  
  //WRITING TO SECOND LED
  digitalWrite(led12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led12, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);  
  
  //WRITING TO THIRD LED
  digitalWrite(led11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led11, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);  
}
