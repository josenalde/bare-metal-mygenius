#include <Arduino.h>
// source: third-party sw! https://github.com/janelia-arduino/Vector/tree/master
#include <Vector.h>
#include "structs.h"
#include "utilsfunc.h"

int stepArray[MAX_STEPS];
Vector<int> stepSequence(stepArray);

int generateRandomStep() {
  /* --- to-do adjust max steps according to hability:
         h1: 8, h2: 14, h3: 20, h4: 31
                                       */  
  int randomKey = random(0,4); //0,1,2,3
    return randomKey;
}
  
  void computerPlay(int f, Keys key[4]) {
    /*-- to-do increase freq each 5 steps +0.2Hz (theory)*/
    for (int i : stepSequence) {
     blinkLed(key[i].ledPin, HIGH); 
     playTone(key[i].toneFreq, f);
     delay(300);
     blinkLed(key[i].ledPin, LOW);
     ledcWriteTone(0, 0);
     delay(300);
    }
  }
  
  void notifyGameOver(Keys key[4]) {
    Serial.println("END GAME...RESTARTING");
    for (int i = 0; i < 4; i++) {
      blinkLed(key[i].ledPin, HIGH);
      delay(10);
      blinkLed(key[i].ledPin, LOW);
      delay(10);
    }
    playTone(100, 200);
    stepSequence.clear();
  }
  
  void playButtonLed(int b, int t) {
     blinkLed(b, HIGH); 
     playTone(t, freq0);
     delay(300);
     blinkLed(b, LOW);
     ledcWriteTone(0, 0);
     delay(300);
  }
  
  void storeSequence(int k) {
    stepSequence.push_back(k); //save step to sequence list
    printSequence();
  }
  
  void blinkLed(int k, int level) {
    digitalWrite(k, level);
  }
  
  void playTone(int k, int f) {
    ledcWriteTone(0, k);
    delay((int)1/f);
  }
  
  void printSequence() {
    Serial.print("Computer sequence: ");
    for (int i : stepSequence) {
      Serial.print(i);
      Serial.print(", ");
    }
    Serial.println("");
  }
  
  int readPlayerKeys(Keys key[4]) {
    //Serial.println("waiting button...");
    /* ---- add non functional requirement if t>=5 gameover - to-do*/
    while (true) {
      for (int i = 0; i < 4; i++) {
        if (!digitalRead(key[i].keyPin)) {
          //Serial.print("i: ");
          //Serial.println(i);
          playButtonLed(key[i].ledPin, key[i].toneFreq);
          return i;
        }
      }
      delay(50); 
   }
  }
  
  bool compareSequence(Keys key[4]) {
    //printSequence();
    for (int i = 0; i < stepSequence.size(); i++) {
      if (readPlayerKeys(key) != stepSequence[i]) {
        Serial.println("Sorry, wrong sentence...finishing game!");
        return false;
      }
    }
    return true;
  }
  
 