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
  bool hasBonfire;
  bool hasEnemy;
  char* enemyName;
  int enemyLevel;
  bool end;
 public:
  Room(const char* newDescription,vector<Room*>* roomList);
  ~Room();
  void takeItem(vector<Item*>* inventory, char* itemName);//Move item to inventory
  void putItem(vector<Item*>* inventory, char* itemName);//Move item to room
  void setExit(const char* exitName, Room* exitRoom);//Create exit
  void setEnemy(const char* name, int level); //Set the Enemy Type, no enemies by default
  void addItem(Item* item);//Place Item in the room
  void printItems(); //Print out the items
  void printExit();//Print out the exits
  void printDescription();//print out everything about the room
  Room* getExit(char* exitKey);//look at the exits
  void giveBonfire();
  bool isCheckpoint();
  bool combat(vector<Item*> inventory);
  bool isEnd();
  void setEnd();
};
#endif
