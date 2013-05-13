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

int ledBlue = 4;
int ledGreen = 3;
int ledRed = 2;

//delay
int ledDelay = 50;

int times = 10;

//RGB LED pins 
int ledDigitalOne[] = {3, 5, 6}; 

const boolean ON = LOW; 
//Define on as LOW (this is because we use a common Anode RGB LED (common pin is connected to +5 volts) 
const boolean OFF = HIGH; 
//Define off as HIGH 
//Predefined Colors 
const boolean RED[] = {ON, OFF, OFF}; 
const boolean GREEN[] = {OFF, ON, OFF}; 
const boolean BLUE[] = {OFF, OFF, ON}; 
const boolean YELLOW[] = {ON, ON, OFF}; 
const boolean CYAN[] = {OFF, ON, ON}; 
const boolean MAGENTA[] = {ON, OFF, ON}; 
const boolean WHITE[] = {ON, ON, ON}; 
const boolean BLACK[] = {OFF, OFF, OFF}; 

//An Array that stores the predefined colors (allows us to later randomly display a color) 
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};
//--- eof RGBL - RGB Digital Preamble 
  

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.  
  
  
  pinMode(led13, OUTPUT);   
  pinMode(led12, OUTPUT); 
  pinMode(led11, OUTPUT);     
  for(int i = 0; i < 3; i++) { 
    //Set the three LED pins as outputs 
    pinMode(ledDigitalOne[i], OUTPUT); 
  } 
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  setRandColor(ledDigitalOne);
  
  //WRITING TO FIRST LED
  digitalWrite(led13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led13, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);               // wait for a second
  
  setRandColor(ledDigitalOne);
    
  //WRITING TO SECOND LED
  digitalWrite(led12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led12, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);  
  
  setRandColor(ledDigitalOne);
  
  //WRITING TO THIRD LED
  digitalWrite(led11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledDelay);               // wait for a second
  digitalWrite(led11, LOW);    // turn the LED off by making the voltage LOW
  delay(ledDelay);  
  times--;
  
  setRandColor(ledDigitalOne);
  
  if(times == 0){
    setRandColor(ledDigitalOne);
    
    digitalWrite(led13, HIGH);
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);

    delay(300);
    
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    
    delay(300);
    
    setRandColor(ledDigitalOne);


    digitalWrite(led13, HIGH);
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);

    delay(300);
    
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    
    delay(300);
    
    setRandColor(ledDigitalOne);
    
    digitalWrite(led13, HIGH);
    digitalWrite(led12, HIGH);
    digitalWrite(led11, HIGH);

    delay(300);
    
    digitalWrite(led13, LOW);
    digitalWrite(led12, LOW);
    digitalWrite(led11, LOW);
    
    delay(300);
    
    colorBounce(ledDigitalOne);
    
    times = 10;
  }
  
}

/* Sets an led to any color led - a three element array defining the three color pins (led[0] = redPin, led[1] = greenPin, led[2] = bluePin) color - a three element boolean array (color[0] = red value (LOW = on, HIGH = off), color[1] = green value, color[2] =blue value)*/ 
  void setColor(int* led, boolean* color){ 
    for(int i = 0; i < 3; i++) { 
      digitalWrite(led[i], color[i]); 
    } 
  }
  
  /* A version of setColor that allows for using const boolean colors*/ 
  void setColor(int* led, const boolean* color) { 
    boolean tempColor[] = {color[0], color[1], color[2]}; 
    setColor(led, tempColor); 
  }
  
  void setRandColor(int* led){
    int rand = random(0, sizeof(COLORS) / 2); 
    //Set the color of led one to a random color 
    setColor(led, COLORS[rand]);
  }
  
  void colorBounce(int* led){
    for(int i = 0; i < sizeof(COLORS) / 2; i++){
      setColor(led, COLORS[i]);
      delay(100);
    }
    for(int i = sizeof(COLORS) / 2 - 1; i >= 0; i--){
      setColor(led, COLORS[i]);
      delay(100);
    }    
  }
