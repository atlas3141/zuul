#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;


Room::Room(const char* newDescription, vector<Room*>* roomList){
  description = strdup(newDescription);
  roomList->push_back(this);
  enemyLevel = -1;
  hasEnemy = false;
}
Room::~Room(){
  delete description;
  delete enemyName;
  for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
    delete *it;
   }
  exits.erase(exits.begin(),exits.end());
}
void Room::takeItem(vector<Item*>* inventory, char* itemName){//Move item to inventory
  for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
    if (!strcmp((*it)->getName(),itemName)){
      inventory->push_back(*it);
      items.erase(it);
      cout << "You picked up a " << itemName << endl;
      return;
    }
  }
  cout << "There is no " << itemName << endl;
} 
void Room::putItem(vector<Item*>* inventory, char* itemName){//Move item to room
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); it++){
    if (!strcmp((*it)->getName(),itemName)){
      items.push_back(*it);
      inventory->erase(it);
      cout << "You dropped your " << itemName << endl;
      return;
    }
  }
  cout << "You don't have a " << itemName << endl;
}
void Room::setExit(const char* exitName, Room* exitRoom){//Create exit
  exits[exitName] = exitRoom;
}
void Room::setEnemy(const char* name, int level){

}
void Room::addItem(Item* item){//Place Item in the room
  items.push_back(item);
}
void Room::printItems(){ //Print out the items
  bool areItems = false;
  for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
    cout << (*it)->getName() << endl;
    areItems = true;
  }
  if (!areItems) 
    cout << "Nothing" << endl;
}
void Room::printExit(){//Print out the exits
  for(map<const char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << (*it).first << endl;
  }
}
void Room::printDescription(){//print out everything about the room
  cout << "You are " << description << endl;
  cout << "There is:" << endl;
  printItems();
  cout << "You can go: " << endl;
  printExit();  
  cout << "-----------------------" << endl;
}
Room* Room::getExit(char* exitKey){//look at the exits
  map<const char*, Room*>::iterator it = exits.find(exitKey);
  if(it != exits.end()){
    return exits[exitKey];
  }
  else {
    return NULL;
  }
}
