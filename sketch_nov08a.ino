#include <MIDI.h>
#include "BetterButton.h"
#include "Arduino.h"
#include "Chord.h"

unsigned long lastStepTime = 0;
int tempo = 1000;
int chordCounter = 0;
int buttonPin = 32;
BetterButton btn1(buttonPin, 1);

Chord C("Maj", "C", "7");
Chord x("Maj", "F");
Chord y("Maj", "G", "b7");
String temp = "";

Chord chordList[] = {C, x, y};


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  btn1.pressHandler(onPress);
  btn1.releaseHandler(onRelease);
  int counter = 0;
  for (int i = 0; i < chordList[chordCounter].NUMNOTES; i++) {

    temp = String(chordList[chordCounter].noteArray[i]);
    Serial.print(temp);
    temp = "";
    if (counter < chordList[chordCounter].NUMNOTES - 1) {
      Serial.print(",");
      counter++;
    }
  }
  Serial.println();

}



void loop() {
  btn1.process();
  playChords(chordCounter);

  //  Serial.println("hi");
  //  for (int i = 0; i < 4; i++) {
  //    temp = String(C.noteArray[i]);
  //    Serial.print(temp);
  //    Serial.print(",");
  //    temp = "";
  //  }
  //  Serial.println();





}

void playChords(int j) {
  if (millis() > lastStepTime + tempo) {
    for (int i = 0; i < chordList[j].NUMNOTES; i++) {
      usbMIDI.sendNoteOff(chordList[j].noteArray[i] + 48, 0, 1);
    }

    for (int i = 0; i < chordList[j].NUMNOTES; i++) {
      usbMIDI.sendNoteOn(chordList[j].noteArray[i] + 48, 127, 1);


    }
    lastStepTime = millis();
  }
}


void onPress(int buttonNum) {
 int counter=0;
  //  Serial.println(chordCounter);

  if (chordCounter + 1 > 2)
    chordCounter = 0;
  else chordCounter++;

  for (int i = 0; i < chordList[chordCounter].NUMNOTES; i++) {

    temp = String(chordList[chordCounter].noteArray[i]);
    Serial.print(temp);
    temp = "";
    if (counter < chordList[chordCounter].NUMNOTES - 1) {
      Serial.print(",");
      counter++;
    }
  }
  Serial.println();

}

void onRelease(int buttonNum) {
  //  Serial.println(" off");
}
