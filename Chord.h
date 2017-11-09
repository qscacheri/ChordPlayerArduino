//
// Created by Quin Scacheri on 11/2/17.
//

#ifndef CHORD_H
#define CHORD_H
using namespace std;
#include "Arduino.h"
class Chord {
public:
  String root;
  int rootNum;
  int *noteArray;
  int NUMNOTES = 3;
  char sharp = '#';
  int suspensions;

  Chord(String q, String r);
  Chord(String q, String r, String sus);
  int note2Num(String note);

  int* getNoteNums();

  int* getNoteArray();

  void printNoteArray();
  
  int getNoteInArray(int i);

  int findThird(int root,String q);

  int findFifth(int root, String q);

  void getNumNotes();

  static int getNumNotesInt();

  String toString();

  int findNumOfSus(String s);

  void findSusNums(String s);

  String rootLetter;


};

#endif //CHORD_H

