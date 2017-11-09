#include "Chord.h"

Chord::Chord(String q, String r) {
  NUMNOTES = 3;
  root = r;
  rootNum = note2Num(root);
  String rootLetter = root;
  noteArray = new int[NUMNOTES];
  noteArray[0] = rootNum;
  noteArray[1] = findThird(rootNum, q);
  noteArray[2] = findFifth(rootNum, q);
}


Chord::Chord(String q, String r, String sus) {
  NUMNOTES = 3;
  root = r;
  rootNum = note2Num(root);
  String rootLetter = root;
  suspensions = findNumOfSus(sus);
  NUMNOTES += suspensions;
  noteArray = new int[NUMNOTES];
  noteArray[0] = rootNum;
  noteArray[1] = findThird(rootNum, q);
  noteArray[2] = findFifth(rootNum, q);
  //  Serial.println(noteArray[2]);
  findSusNums(sus);

}



int Chord::note2Num(String note) {
  int noteNum = 0;

  if (note == "C")
    noteNum = 0;
  else if (note == "C#" || note == "Db")
    noteNum = 1;
  else if (note == "D")
    noteNum = 2;
  else if (note == "D#" || note == "Eb")
    noteNum = 3;
  else if (note == "E")
    noteNum = 4;
  else if (note == "F")
    noteNum = 5;
  else if (note == "F#" || note == "Gb")
    noteNum = 6;
  else if (note == "G")
    noteNum = 7;
  else if (note == "G#" || note == "Ab")
    noteNum = 8;
  else if (note == "A")
    noteNum = 9;
  else if (note == "A#" || note == "Bb")
    noteNum = 10;
  else if (note == "B")
    noteNum = 11;
  return noteNum;
}

int Chord::findThird(int root, String q) {
  int mod = 0;
  if (q.equals("Maj")) {
    mod = 0;
  } else if (q.equals("min")) {
    mod = -1;
  } else if (q.equals("dim")) {
    mod = -1;
  }

  if (rootNum + 4 > 11 + mod) {
    return rootNum - 8 - mod;
  } else
    return rootNum + 4 + mod;
}

int Chord::findFifth(int root, String q) {
  int mod = 0;
  if (q.equals("Maj")) {
    mod = 0;
  } else if (q.equals("min")) {
    mod = 0;
  } else if (q.equals("dim")) {
    mod = -1;
  }

  if (rootNum + 7 +mod> 11) {
    return rootNum - 5 - mod;
  } else
    return rootNum + 7 + mod;
}




int Chord::findNumOfSus(String s) {
  int counter = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s.charAt(i) == ',') {
      counter++;
    }
  }
  return counter + 1;
}

int Chord::getNoteInArray(int i) {
  return noteArray[i];
}

void Chord::findSusNums(String s) {
  int mod;
  String temp = "";
  int tempNum;
  int susCounter = 3;
  String susArray[suspensions];
  int arrayCounter = 0;


  //MAKES ARRAY OF SUSPENSIONS
  for (int i = 0; i < s.length() + 1; i++) {

    if (s.charAt(i) != ',') {

      temp += s.charAt(i);

    }
    else if (s.charAt(i) == ',') {

      susArray[arrayCounter] = temp;
      arrayCounter++;
      temp = "";
    }

  }
  susArray[arrayCounter] = temp;



  for (int i = 0; i < suspensions; i++) {
    tempNum = 0;
    temp = "";
    int startPoint;
    if (susArray[i].charAt(0) == 'b' || susArray[i].charAt(0) == '#')
      
      startPoint = 1;
    else
      startPoint = 0;

    for (int k = startPoint; k < susArray[i].length(); k++) {
      temp += susArray[i].charAt(k);
      tempNum = temp.toInt();
    }

    if (susArray[i].charAt(0) == 'b'){
      mod = -1;
//      Serial.println("is flat");
    }

    else if (susArray[i].charAt(0) == '#'){
      mod = 1;
      Serial.println("is sharp");
    }
    else
      mod = 0;

    if (tempNum == 7) {
      if (mod + rootNum + 11 > 11) {
        tempNum = rootNum - 1 + mod;
      } else
        tempNum = rootNum + 11 - mod;
    } else if (tempNum == 9) {
      if (rootNum + 2 + mod > 11) {
        tempNum = rootNum - 10 + mod;
      } else
        tempNum = rootNum + 2 - mod;
    } else if (tempNum == 11) {
      if (rootNum + 5 + mod > 11) {
        tempNum = rootNum - 7 + mod;
      } else
        tempNum = rootNum + 5 - mod;
    } else if (tempNum == 13) {
      if (rootNum + 9 + mod > 11) {
        tempNum = rootNum - 3 - mod;
      } else {
        tempNum = rootNum + 9 + mod;
      }

    }
    noteArray[susCounter] = tempNum;
    susCounter++;
  }

}

void Chord::printNoteArray() {
  for (int i = 0; i < NUMNOTES; i++)
    Serial.println(noteArray[i]);
}



