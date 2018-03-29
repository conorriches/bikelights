#include "FastLED.h"

// How many leds in your strip?
#define NUM_CENTRE_LEDS 14
#define NUM_LEFT_LEDS 7
#define NUM_RIGHT_LEDS 7
#define NUM_FRONT_LEDS 4

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define CENTRE_PIN 5
#define LEFT_PIN 2
#define RIGHT_PIN 3
#define FRONT_PIN 4

// Define the array of leds
CRGB leftLeds[NUM_LEFT_LEDS];
CRGB rightLeds[NUM_RIGHT_LEDS];
CRGB centreLeds[NUM_CENTRE_LEDS];
CRGB frontLeds[NUM_FRONT_LEDS];

void setup() { 
  delay(2000);
  FastLED.addLeds<NEOPIXEL, CENTRE_PIN>(centreLeds, NUM_CENTRE_LEDS);
  FastLED.addLeds<NEOPIXEL, LEFT_PIN>(leftLeds, NUM_LEFT_LEDS);
  FastLED.addLeds<NEOPIXEL, RIGHT_PIN>(rightLeds, NUM_RIGHT_LEDS);
  FastLED.addLeds<NEOPIXEL, FRONT_PIN>(frontLeds, NUM_FRONT_LEDS);
  delay(500);
  //fill_solid(centreLeds, NUM_CENTRE_LEDS, CRGB::Purple);
  for(int i = 0 ; i < NUM_CENTRE_LEDS ; i ++){
    if (i % 2 == 0) centreLeds[i] = CRGB::White;
    else centreLeds[i] = CRGB::Azure;
  }
  fill_solid(leftLeds, NUM_LEFT_LEDS, CRGB::Red);
  fill_solid(rightLeds, NUM_RIGHT_LEDS, CRGB::Red);
  fill_solid(frontLeds, NUM_FRONT_LEDS, CRGB::White);
  FastLED.setBrightness(255);
  FastLED.show();
}

void loop() { 

  for(int i = 0 ; i < NUM_LEFT_LEDS ; i ++){
    leftLeds[i] = CHSV(0,255,255);
    rightLeds[i] = CHSV(0,255,255);
    FastLED.show();
    delay(20);
  }
delay(500);
  for(int i = 0 ; i < NUM_LEFT_LEDS ; i ++){
    leftLeds[i] = CHSV(0,255,055);
    rightLeds[i] = CHSV(0,255,055);
    FastLED.show();
    delay(20);
  }

 
 
   
}
