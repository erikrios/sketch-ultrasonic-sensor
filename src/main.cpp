#include <Arduino.h>

#define PIN_TRIG 2
#define PIN_ECHO 3
#define PIN_LED_RED 8
#define PIN_LED_YELLOW 9
#define PIN_LED_GREEN 10

void setLedState(byte ledRedState, byte ledYellowState, byte ledGreenState);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.println(distance);

  if (distance <= 8)
  {
    setLedState(HIGH, LOW, LOW);
  } else if (distance <= 15)
  {
    setLedState(LOW, HIGH, LOW);
  } else
  {
    setLedState(LOW, LOW, HIGH);
  }

  delay(500);
}

void setLedState(byte ledRedState, byte ledYellowState, byte ledGreenState) {
  digitalWrite(PIN_LED_RED, ledRedState);
  digitalWrite(PIN_LED_YELLOW, ledYellowState);
  digitalWrite(PIN_LED_GREEN, ledGreenState);
}