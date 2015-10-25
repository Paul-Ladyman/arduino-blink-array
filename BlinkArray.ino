const int FAST = 125;
const int SLOW = 250;
const int PAUSESPEED = 250;
int numLeds = 4;
int leds[4] = {8, 7, 4, 2};
int led1 = 8;
int led2 = 7;
int led3 = 4;
int led4 = 2;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  int i;
  for (i = 0; i < numLeds; i = i + 1) {
    pinMode(leds[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  sequentialBlink(FAST);
  delay(PAUSESPEED);
  reverseSequentialBlink(SLOW);
  delay(PAUSESPEED);
  blink(led2, FAST);
  blink(led4, SLOW);
  blink(led1, FAST);
  blink(led3, SLOW);
  delay(PAUSESPEED);
  blinkAll(FAST);
  delay(PAUSESPEED);
}

void blink(int pin, int blinkSpeed) {
  digitalWrite(pin, HIGH);
  delay(blinkSpeed);
  digitalWrite(pin, LOW);
  delay(blinkSpeed);  
}

void sequentialBlink(int blinkSpeed) {
  int i;
  for (i = 0; i < numLeds; i = i + 1) {
    digitalWrite(leds[i], HIGH);
    delay(blinkSpeed);
    digitalWrite(leds[i], LOW);
    delay(blinkSpeed); 
  }
}

void reverseSequentialBlink(int blinkSpeed) {
  int i;
  for (i = numLeds - 1; i >= 0; i = i - 1) {
    digitalWrite(leds[i], HIGH);
    delay(blinkSpeed);
    digitalWrite(leds[i], LOW);
    delay(blinkSpeed); 
  }
}

void blinkAll(int blinkSpeed) {
  allToDigital(HIGH);
  delay(blinkSpeed);
  allToDigital(LOW);
  delay(blinkSpeed);
}

void allToDigital(int value) {
  int i;
  for (i = 0; i < numLeds; i = i + 1) {
    digitalWrite(leds[i], value);
  }
}
