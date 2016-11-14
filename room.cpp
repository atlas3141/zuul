#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"
#include "room.h"

using namespace std;


room::room(char newDescription[300]){

}
void room::takeItem(vector<item*>* inventory, char* itemName){//Move item to inventory
} 
void room::putItem(vector<item*>* inventory, char* itemName){//Move item to room
}
void room::setExit(const char* exitName, room* exitRoom){//Create exit
}
void room::addItem(item* Item){//Place Item in the room
}
void room::printItems(){ //Print out the items
}
void room::printExit(){//Print out the exits
}
void room::printDescription(){//print out everything about the room
}
room* room::getExit(char* exitKey){//look at the exits
}
