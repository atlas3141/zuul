#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;


Room::Room(char* newDescription){
  description = newDescription;
}
void Room::takeItem(vector<Item*>* inventory, char* itemName){//Move item to inventory
} 
void Room::putItem(vector<Item*>* inventory, char* itemName){//Move item to room
}
void Room::setExit(const char* exitName, Room* exitRoom){//Create exit
  exits[exitName] = exitRoom;
}
void Room::addItem(Item* item){//Place Item in the room
}
void Room::printItems(){ //Print out the items
  for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
    cout << (*it)->getName();
  }
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
}
Room* Room::getExit(char* exitKey){//look at the exits
  return exits[exitKey];
}
