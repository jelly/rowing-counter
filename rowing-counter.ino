#include <FastLED.h>

const bool _ = false;
const bool X = true;
const int buttonpin = 39;
const int ledpin = 27;
const int numleds = 25;

CRGB leds[numleds];

const bool digits[] = {
  X,X,X,  _,X,_,  X,X,X,  X,X,X,  X,_,X,  X,X,X,  _,X,X,  X,X,X,  X,X,X,  X,X,X,
  X,_,X,  _,X,_,  _,_,X,  _,_,X,  X,_,X,  X,_,_,  X,_,_,  _,_,X,  X,_,X,  X,_,X,
  X,_,X,  _,X,_,  X,X,X,  X,X,X,  X,X,X,  X,X,X,  X,X,X,  _,X,_,  X,X,X,  X,X,X,
  X,_,X,  _,X,_,  X,_,_,  _,_,X,  _,_,X,  _,_,X,  X,_,X,  _,X,_,  X,_,X,  _,_,X,
  X,X,X,  _,X,_,  X,X,X,  X,X,X,  _,_,X,  X,X,X,  X,X,X,  _,X,_,  X,X,X,  X,X,_
};

void setup() {
    pinMode(buttonpin, INPUT);
    FastLED.addLeds < WS2812B, ledpin, GRB > (leds, numleds);
    FastLED.setBrightness(20);


    FastLED.showColor(CRGB::Blue);
    delay(500);
    FastLED.showColor(CRGB::Black);
}

void countdown(unsigned int seconds, CRGB color) {
	for (unsigned int n = seconds; n > 0; n--) {
		int first  = n / 10;
		int second = n % 10;

		for (int i = 0; i < numleds; i++) leds[i] = CRGB::Black;

		for (int y = 0; y < 5; y++) {
		if (first) leds[y*5] = color;  // digit 1 or nothing

		for (int x = 0; x < 3; x++) {
		if (digits[y*30 + second*3 + x]) leds[y*5 + first + 1 + x] = color;
		}
		}
		FastLED.show();

		delay(1000);
	}
}

void loop() {
	if (digitalRead(buttonpin) == LOW) {
		// Start
		countdown(10, CRGB::Green);
		for (unsigned int sets = 10; sets > 0; sets--) {
			// Row
			countdown(20, CRGB::Red);
			// Cooldown
			countdown(10, CRGB::Blue);
		}
	}
}
