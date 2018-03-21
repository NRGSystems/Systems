#include <Joystick.h>
#include <Adafruit_NeoPixel.h>

//Adafruit Lights

Adafruit_NeoPixel strip = Adafruit_NeoPixel(100, 12);

// Create Joystick
Joystick_ joystick;


int lightGreen = 10;
int lightStripSwitch = 8;
boolean stripOn = true;

// number of inputs
const int nInputs = 11;
// inputs (as many as nInputs)
int noAuto = 0;
int forwardAuto = 1;
int switchAuto = 2;
int scaleAuto = 3;
int switchScaleAuto = 4;
int emptyAuto = 5;
int leftPosition = 6;
int rightPosition = 7;
int climb = 9;
int noClimb = 11; // not an actual pin
int centerPosition = 12; //not an actual pin

// store all of the input indices in an array
// On the joystick: climb = 1, noVision = 2, vision = 3, pos1 = 4, pos2 = 5, pos3 = 6, auto1 = 7, auto2 = 8, auto3 = 9, noAuto = 10, acquirerForward = 11, acquirerBackward = 13, shoot = 14, rpmShooter = 15
int index[nInputs] = {noAuto, forwardAuto, switchAuto, scaleAuto, switchScaleAuto, emptyAuto, leftPosition, centerPosition, rightPosition, climb, noClimb};

// Last state of the button
int lastButtonState[nInputs];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < nInputs; i ++) {
    lastButtonState[i] = 0;
  }
  
  for (int i = 0; i < nInputs; i ++) {
    pinMode(index[i], INPUT_PULLUP);
  }

  // Initialize Joystick Library
  joystick.begin();

  //set light switch
  pinMode(lightStripSwitch, INPUT_PULLUP);

  //turn on initial lights
  strip.begin();
  strip.show();
  for(int i = 0; i<100; i++){
    int red = 255 - (i * 2);
    int green = i * 2;
    strip.setPixelColor(i, red, green, 0);
  }
  strip.show();

  
}


void loop() {

  //Serial.print(digitalRead(lightStripSwitch));
  //check to turn off lights
 /* if((digitalRead(lightStripSwitch) == LOW) && stripOn == true){
    stripOn = false;
    for(int i = 0; i < 60; i++){
      strip.setPixelColor(i, 0, 0, 0);
  }
    strip.show();
    Serial.print("wow");
  }
  //check to turn on lights
  if(digitalRead(lightStripSwitch) == HIGH && stripOn == false){
    stripOn = true;
    for(int i = 0; i < 60; i++){
      strip.setPixelColor(i, 255, 0, 0);
    }
    strip.show();
    Serial.print("something!");
  }

  if(digitalRead(noAuto) == LOW){
    digitalWrite(lightGreen, HIGH);
  } */

  
  // Read pin values
  for (int i = 0; i < nInputs; i++)
  {
    int currentButtonState = !digitalRead(index[i]);
    if (currentButtonState != lastButtonState[i])
    {
      joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  } 
  
  // update the readings from the "not an actual" pins
  if (digitalRead(climb) == HIGH) {
    joystick.setButton(10, HIGH);
  } else {
    joystick.setButton(10, LOW);
  }
  if (digitalRead(leftPosition) == HIGH && digitalRead(rightPosition) == HIGH) {
    joystick.setButton(7, HIGH);
  } else {
    joystick.setButton(7, LOW);
  }
}
