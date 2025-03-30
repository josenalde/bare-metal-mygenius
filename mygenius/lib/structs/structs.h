#ifndef STRUCTS_H
#define STRUCTS_H

#include <Arduino.h>

struct Keys {
    int toneFreq;
    String color;
    int ledPin;
    int keyPin;
};
#endif