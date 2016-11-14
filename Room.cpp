#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;


Room::Room(char newDescription[300]){

}
void Room::takeItem(vector<Item*>* inventory, char* itemName){//Move item to inventory
} 
void Room::putItem(vector<Item*>* inventory, char* itemName){//Move item to room
}
void Room::setExit(const char* exitName, Room* exitRoom){//Create exit
}
void Room::addItem(Item* item){//Place Item in the room
}
void Room::printItems(){ //Print out the items
}
void Room::printExit(){//Print out the exits
}
void Room::printDescription(){//print out everything about the room
}
Room* Room::getExit(char* exitKey){//look at the exits
}
