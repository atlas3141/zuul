# include <iostream>
# include <cstring>
# include <vector>
# include "Room.h"
# include "Item.h"
using namespace std;

bool firstWordCmp(char* a, const char* b);
void strToLower(char* a);

int main(){
  vector<Item*> inventory;
  vector<Room*> roomList;
  Room* currentRoom;
  char input[30];
  bool playing = true;

  Room* firstRoom = new Room("In the first Room");
  Room* secondRoom = new Room("In the second room");

  Item* item1 = new Item("sword");

  firstRoom->setExit("north", secondRoom);
  firstRoom->addItem(item1);

  secondRoom->setExit("south", firstRoom);
  roomList.push_back(firstRoom);

  currentRoom = firstRoom;
 
  currentRoom->printDescription();

  while (playing = true){
    
    cin.get(input,30);
    strToLower(input);

    if (firstWordCmp(input,"go")){
      Room* newRoom = currentRoom->getExit(input + 3);
      if (newRoom){
	currentRoom = newRoom;
	currentRoom->printDescription();
      }
    }
    if (firstWordCmp(input,"get")){
      currentRoom->takeItem(&inventory,input +4);
    }
    if (firstWordCmp(input,"drop")){
      currentRoom->putItem(&inventory, input + 5);
    }
    if (firstWordCmp(input,"inventory")){
      bool haveItems = false;
      for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	cout << (*it)->getName();
	haveItems = true;
      }
      if (!haveItems)
	cout << "You dont have anything" << endl;
    }
    if (firstWordCmp(input,"help")){
      currentRoom->printDescription();
    }
    if (firstWordCmp(input,"quit")){
    }
    cin.ignore();
  }
}
bool firstWordCmp(char* a, const char* b){
  for(int i = 0; i < strlen(b); i++){
    if (a[i] != b[i])
      return false;
  }
  return true;
}
void strToLower(char* a){
  while(*a){
    *a = tolower(*a);
    a++;
  }
}
