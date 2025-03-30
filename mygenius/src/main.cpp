
/* by Josenalde Oliveira - embedded software developer */

#include <Arduino.h>
#include "structs.h"
#include "utilsfunc.h"

//int gameType = 1; //1,2,3 ---- to-do handle different games
//bool startButtonIsPressed = false; // not used so far
//bool error = false, ack = false; // not used so far

int step;

Keys key[4] = {{261, "yellow", 12, 13},
               {440, "blue", 4, 15},
               {329, "red", 16, 19},
               {392, "green", 14, 27}};

void setup() {
      
  Serial.begin(115200);
  
  pinMode(powerSwitch, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(powerLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(key[i].keyPin, INPUT_PULLUP);
    pinMode(key[i].ledPin, OUTPUT);
  }
  
  //esp32 does not have tone/notone - by Josenalde 29.03.25
  ledcSetup(0, 2000, 8);
  ledcAttachPin(buzzerPin, 0);

  randomSeed(analogRead(34)); //rng seed (floating pin)
}

void loop() {
  if (!digitalRead(powerSwitch)) {
     digitalWrite(powerLed, HIGH);
     /*---- to-do handle start button ----- */   
        step = generateRandomStep();
        storeSequence(step);
        computerPlay(freq0, key);
        if (!compareSequence(key)) {
          notifyGameOver(key);
          delay(1000);
        }
  } else {
    digitalWrite(powerLed, LOW);
  }
}
