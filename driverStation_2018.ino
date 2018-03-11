#include <Joystick.h>
//#include <Adafruit_NeoPixel.h>

//Adafruit Lights
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 13);

// Create Joystick
Joystick_ joystick;


int lightGreen = 10;
int lightStripSwitch = 8;

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

  // Initialize outputs
  //pinMode(lightGreen, OUTPUT);
  //pinMode(lightStripSwitch, INPUT_PULLUP);
  
  // Initialize Strip
  //strip.begin();  
  //strip.show();
  
  // inputs0
  0000000000000000000000000000000000000000000000000000000000000000000





  
  for (int i = 0; i < nInputs; i ++) {
    pinMode(index[i], INPUT_PULLUP);
  }

  // Initialize Joystick Library
  joystick.begin();
}


void loop() {

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
 // Serial.print(digitalRead(rightPosition));
  // set the lights
 /* digitalWrite(lightGreen, HIGH);
  if (digitalRead(noAuto) == LOW) {
    digitalWrite(lightGreen, HIGH);
  } else {
    digitalWrite(lightGreen, LOW);
  }
  if (digitalRead(lightStripSwitch) == LOW) {
    for (int cho = 0; cho <= 3; cho++){
      for (int pos = 0; pos <= 59; pos++) {
        for (int tai = pos; tai >= pos-17; tai--) {
          int brio = (pos-tai) * 2;
          int brit = 34 - brio;
          if(cho == 0){
            strip.setPixelColor(tai, brit, 0, brio);
          }
          else if(cho == 1){
            strip.setPixelColor(tai, brio, brio, brit);
          }
          else if(cho == 2){
            strip.setPixelColor(tai, brio, brit, 0);
          }
          else{
            strip.setPixelColor(tai, 34, brit, 0);
          }
        }
        for (int pose = pos - 17; pose >=0; pose--) {
          strip.setPixelColor(pose, 0, 0, 0);
        }
        delay(15);
        strip.show();
      }
      for (int pose = 42; pose <= 59; pose++) {
        strip.setPixelColor(pose, 0, 0, 0);
        delay(15);
        strip.show();
      }
    }
  }
  delay(50);
  */
}
