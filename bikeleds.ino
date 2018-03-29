/**
 * Bike LEDs by conorriches
 * Simple sketch to illuminate WS2812B leds, 
 * with a strip of LEDs on each pin.
 */

#include "FastLED.h"

// Define how many LEDs we have in each strip.
#define NUM_CENTRE_LEDS 14
#define NUM_LEFT_LEDS 7
#define NUM_RIGHT_LEDS 7
#define NUM_FRONT_LEDS 4

// Define the pins that each strip is connected to.
#define CENTRE_PIN 5
#define LEFT_PIN 2
#define RIGHT_PIN 3
#define FRONT_PIN 4

// Define our arrays of LEDs according to the number for each
CRGB leftLeds[NUM_LEFT_LEDS];
CRGB rightLeds[NUM_RIGHT_LEDS];
CRGB centreLeds[NUM_CENTRE_LEDS];
CRGB frontLeds[NUM_FRONT_LEDS];

void setup()
{
  // All FastLED examples start with a delay
  delay(2000);

  // Add our LED strips so FastLED is aware of them.
  FastLED.addLeds<NEOPIXEL, CENTRE_PIN>(centreLeds, NUM_CENTRE_LEDS);
  FastLED.addLeds<NEOPIXEL, LEFT_PIN>(leftLeds, NUM_LEFT_LEDS);
  FastLED.addLeds<NEOPIXEL, RIGHT_PIN>(rightLeds, NUM_RIGHT_LEDS);
  FastLED.addLeds<NEOPIXEL, FRONT_PIN>(frontLeds, NUM_FRONT_LEDS);

  // Set the LEDs to starting colours
  initialiseLEDs();
}

/**
 * Runs continually
 */
void loop()
{

  // Animate LEDs to full red brightness
  for (int i = 0; i < NUM_LEFT_LEDS; i++)
  {
    leftLeds[i] = CHSV(0, 255, 255);
    rightLeds[i] = CHSV(0, 255, 255);
    FastLED.show();
    delay(20);
  }

  // Show them to Audi/BWM drivers ಠ_ಠ
  delay(500);

  // Animate LEDs to dim red brightness
  for (int i = 0; i < NUM_LEFT_LEDS; i++)
  {
    leftLeds[i] = CHSV(0, 255, 055);
    rightLeds[i] = CHSV(0, 255, 055);
    FastLED.show();
    delay(20);
  }

  //No delay here as we immediately want to re-animate to full brightness.

}

/**
 * How we want our LEDs to start off
 */
void initialiseLEDs() {

  // Subtle pattern for the downward facing LEDs
  for (int i = 0; i < NUM_CENTRE_LEDS; i++)
  {
    if (i % 2 == 0)
      centreLeds[i] = CRGB::White;
    else
      centreLeds[i] = CRGB::Azure;
  }

  // Set the back LEDs to RED
  fill_solid(leftLeds, NUM_LEFT_LEDS, CRGB::Red);
  fill_solid(rightLeds, NUM_RIGHT_LEDS, CRGB::Red);

  // Set the front LEDs to White
  fill_solid(frontLeds, NUM_FRONT_LEDS, CRGB::White);

  // Show them at full brightness.
  FastLED.setBrightness(255);
  FastLED.show();
}