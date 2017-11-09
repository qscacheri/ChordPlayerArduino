#include "Arduino.h"
#include "BetterButton.h"

BetterButton::BetterButton(int _buttonPin, int _buttonNum)
{
  buttonPin = _buttonPin;
  buttonNum = _buttonNum;
  buttonState = 0;
  lastButtonState = 0;

  pinMode(buttonPin, INPUT);

  lastCheck = 0;
  checkInt = 100;
}

void BetterButton::process()
{
  if (millis() < lastCheck + checkInt) return;

  lastCheck = millis();

  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && buttonState == HIGH) {
    pressCallback(buttonNum);
  }
  if (lastButtonState == HIGH && buttonState == LOW) {
    releaseCallback(buttonNum);
  }
}

int BetterButton::returner(){
  return 22; 
}

void BetterButton::pressHandler(void (*f)(int))    //button down
{
  pressCallback = *f;
}

void BetterButton::releaseHandler(void (*f)(int))  //button release
{
  releaseCallback = *f;
}
