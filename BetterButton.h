#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class BetterButton
{
  public:
    BetterButton(int _buttonPin, int _buttonNum);
    int returner();
    void process();
    void pressHandler(void (*f)(int));
    void releaseHandler(void (*f)(int));
    void (*pressCallback)(int);
    void (*releaseCallback)(int);

    int buttonNum;
    int buttonPin;
    bool firstCheck;
    bool buttonState;
    bool lastButtonState;
    unsigned long lastCheck;
    int checkInt;

  private:
};

#endif
