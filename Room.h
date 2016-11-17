#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

struct cmp_string{
  bool operator()(char const *a, char const *b){
    return strcmp(a,b) < 0;
  }
};

class Room{
 private:
  map<const char*, Room*, cmp_string> exits;
  vector<Item*> items;
  char* description;
 public:
  Room(char* newDescription,vector<Room*>* roomList);
  void takeItem(vector<Item*>* inventory, char* itemName);//Move item to inventory
  void putItem(vector<Item*>* inventory, char* itemName);//Move item to room
  void setExit(const char* exitName, Room* exitRoom);//Create exit
  void addItem(Item* item);//Place Item in the room
  void printItems(); //Print out the items
  void printExit();//Print out the exits
  void printDescription();//print out everything about the room
  Room* getExit(char* exitKey);//look at the exits
};
#endif
