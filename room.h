#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

struct cmp_string{
  bool operator()(char const *a, char const *b){
    return strcmp(a,b) < 0;
  }
};

class room{
 private:
  map<const char*, room*, cmp_string> exits;
  vector<item*> items;
  char description[300];
 public:
  room(char newDescription[300]);
  void takeItem(vector<item*>* inventory, char* itemName);//Move item to inventory
  void putItem(vector<item*>* inventory, char* itemName);//Move item to room
  void setExit(const char* exitName, room* exitRoom);//Create exit
  void addItem(item* Item);//Place Item in the room
  void printItems(); //Print out the items
  void printExit();//Print out the exits
  void printDescription();//print out everything about the room
  room* getExit(char* exitKey);//look at the exits
}
#endif
