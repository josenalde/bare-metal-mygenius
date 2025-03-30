#ifndef UTILSFUNC_H
#define UTILSFUNC_H

//by Josenalde Oliveira 2025.march

#define MAX_STEPS 31
#define freq0 200 // 1.2Hz theory
#define incrementFreq 200

//---pins
#define startButton 22
#define powerSwitch 5
#define buzzerPin 25
#define powerLed 26

/*struct keys {
  int toneFreq;
  String color;
  int ledPin;
  int keyPin;
};*/
// freq, color, ledpin, keypin  
/*keys key[4] = {{261, "yellow", 12, 13},
             {440, "blue", 4, 15},
             {329, "red", 16, 19},
             {392, "green", 14, 27}};*/


// functions signatures
int generateRandomStep();
void computerPlay(int f, Keys[]);
void storeSequence(int);
void blinkLed(int k, int level); 
void playTone(int k, int f);
int readPlayerKeys(Keys[]);
bool compareSequence(Keys[]);
void printSequence();
void playButtonLed(int b, int t);
void printSequenceB();
void notifyGameOver(Keys[]);
#endif