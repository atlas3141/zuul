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

  firstRoom->setExit("north", secondRoom);

  roomList.push_back(firstRoom);

  currentRoom = firstRoom;
 
  currentRoom->printDescription();

  while (playing = true){
    cin.get(input,30);
    strToLower(input);

    if (firstWordCmp(input,"go")){
      if (currentRoom->getExit(input + 3)){
	currentRoom = currentRoom->getExit(input+3);
	currentRoom->printDescription();
      }
    }
    if (firstWordCmp(input,"get")){
      cout << "What" << endl;
    }
    if (firstWordCmp(input,"drop")){

    }
    if (firstWordCmp(input,"inventory")){

    }
    if (firstWordCmp(input,"help")){

    }
    if (firstWordCmp(input,"quit")){
    }
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
