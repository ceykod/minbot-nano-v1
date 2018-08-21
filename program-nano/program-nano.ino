#include "define.h"

volatile int mode = BEGIN;

void setup() {

  Serial.begin(9600);
  Serial.println(">> Minbot-Nano-v1 Begin");

  motorBegin();

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_1, OUTPUT);
  
  delay(500);
}

void test() {

}

void beep(int count) {

  for (int i = 0; i < count; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
  }
}

