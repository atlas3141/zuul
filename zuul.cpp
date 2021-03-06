# include <iostream>
# include <cstring>
# include <vector>
# include "Room.h"
# include "Item.h"
using namespace std;
//Zuul, a text based adventure game, this one is a recreation of the first areas of dark souls
bool firstWordCmp(char* a, const char* b);
void strToLower(char* a);

void roomSetup(vector<Room*>* roomList){ //this is a hundred lines of setup, lots of fun
  Room* firelink_shrine = new Room("in a ruined shrine built around a bonfire. There are people around. You are safe.", roomList);
  Room* graveyard = new Room("in a large graveyard, there are items and skeletons all around", roomList);
  Room* aquaduct = new Room("in a rotting aquaduct over a cliff", roomList);
  Room* parish_elevators = new Room("by an elevator shaft that leads up to a church on the hill. The elevator seems to be broken", roomList);
  Room* church_floor = new Room("in a massive church", roomList);
  Room* upper_catacombs = new Room("in a dark cave with open graves", roomList);
  Room* new_londo_elevator = new Room ("in a large elevator shaft that goes far below the shrine.", roomList);
  Room* lower_burg_rooftops = new Room("on the rooftops of the undead burg", roomList);
  Room* undead_burg_bonfire = new Room("by a bonfire on the rooftops of the burg, theres a ladder leading even further up.", roomList);
  Room* undead_burg_towers = new Room("on the areas that connect all the towers of the burg", roomList);
  Room* havels_tower = new Room ("in a massive tower", roomList);
  Room* taurus_bridge = new Room (" on a 1000 foot bridge", roomList);
  Room* bridge_balcony = new Room ("on a balcony looking over the wilderness", roomList);
  Room* dragon_bridge = new Room ("on a 500 foot bridge leading to a sunlit shrine", roomList);
  Room* under_bridge = new Room ("underneeth the 500 foot bridge", roomList);
  Room* boar_alley = new Room ("in a long alley leading towards the parish", roomList);
  Room* church_courtyard = new Room("in front of the main entrance to the parish", roomList);
  Room* church_passage = new Room("in a tall room filled with rotting tables and beds", roomList);
  Room* outside_church = new Room("outside the church near a bridge leading to a tower", roomList);
  Room* andres_tower = new Room("in a decrepit tower.", roomList);
  Room* upper_church = new Room("in the upper level of the Parish", roomList);
  Room* church_roof = new Room("on the roof of the Parish", roomList);
  Room* bell_tower = new Room("on the highest point in the undead burg, the bell tower", roomList);

  // initialise room exits 
  firelink_shrine->setExit("west", graveyard);
  firelink_shrine->setExit("north", parish_elevators);
  firelink_shrine->setExit("east", aquaduct);
  firelink_shrine->setExit("south", new_londo_elevator);

  graveyard->setExit("east", firelink_shrine);
  graveyard->setExit("west",upper_catacombs);
        
  upper_catacombs->setExit("east",graveyard);

  aquaduct->setExit("west", firelink_shrine);
  aquaduct->setExit("north", lower_burg_rooftops);
        
  lower_burg_rooftops->setExit("south", aquaduct);
  lower_burg_rooftops->setExit("north", undead_burg_bonfire);
        
  undead_burg_bonfire->setExit("south", lower_burg_rooftops);
  undead_burg_bonfire->setExit("north",undead_burg_towers);
  undead_burg_bonfire->setExit("up", bridge_balcony);
        
  undead_burg_towers->setExit("south",undead_burg_bonfire);
  undead_burg_towers->setExit("north",havels_tower);
        
  havels_tower->setExit("south",undead_burg_towers);
  havels_tower->setExit("up", taurus_bridge);
        
  taurus_bridge->setExit("south", havels_tower);
  taurus_bridge->setExit("north",  bridge_balcony);
        
  bridge_balcony->setExit("south", taurus_bridge);
  bridge_balcony->setExit("down", undead_burg_bonfire);
  bridge_balcony->setExit("up",dragon_bridge);
  bridge_balcony->setExit("north", under_bridge);
        
  dragon_bridge->setExit("down", bridge_balcony);
  dragon_bridge->setExit("north",boar_alley);
        
  under_bridge->setExit("south", bridge_balcony);
  under_bridge->setExit("up",boar_alley);
        
  boar_alley->setExit("south", dragon_bridge);
  boar_alley->setExit("down",under_bridge);
  boar_alley->setExit("north", church_courtyard);
  boar_alley->setExit("up", church_passage);

  church_passage->setExit("down", boar_alley);
  church_passage->setExit("up",outside_church);
        
  outside_church->setExit("west",church_courtyard);
  outside_church->setExit("east", andres_tower);
  outside_church->setExit("north",church_floor);
        
  church_courtyard->setExit("east",outside_church);
  church_courtyard->setExit("south", boar_alley);
  church_courtyard->setExit("north",church_floor);
        
  parish_elevators->setExit("south", firelink_shrine);

  church_floor->setExit("south",church_courtyard);
  church_floor->setExit("east", outside_church);
  church_floor->setExit("up", upper_church);
        
  upper_church->setExit("down",church_floor);
  upper_church->setExit("up", church_roof);
        
  church_roof->setExit("down", upper_church);
  church_roof->setExit("up", bell_tower);
        
  bell_tower->setExit("down", church_roof);
  
  graveyard->setEnemy("skeletons",1);
  church_floor->setEnemy("Kights of Balder",1);
  lower_burg_rooftops->setEnemy("Undead Peasants",0);
  undead_burg_towers->setEnemy("Undead Soldiers",1);
  havels_tower->setEnemy("Havel Knight",2);
  under_bridge->setEnemy("Giant Rats",1);
  dragon_bridge->setEnemy("Helkite Drake",3);
  boar_alley->setEnemy("Armored Boar",2);
  upper_church->setEnemy("Chaneler",2);
  church_roof->setEnemy("Gargoyles",3);
  taurus_bridge->setEnemy("Taurus Demon",2);
      
  firelink_shrine->giveBonfire();
  undead_burg_bonfire->giveBonfire();
  andres_tower->giveBonfire();

  parish_elevators->addItem(new Item("longsword",2));
  graveyard->addItem(new Item("zweihander",3));
  lower_burg_rooftops->addItem(new Item("firebombs",3));

  bell_tower->setEnd();
 } 
int main(){ //start here
  vector<Item*> inventory;
  vector<Room*> roomList;
  Room* currentRoom;
  Room* currentCheckpoint;
  char input[30];
  bool playing = true;

  Item* hands = new Item("fists", 0);
  Item* pendant = new Item("pendant", 0);
  Item * hilt = new Item("hilt",0);
  inventory.push_back(hands);
  inventory.push_back(pendant);
  inventory.push_back(hilt);


  roomSetup(&roomList);
  currentRoom = *roomList.begin();
  currentCheckpoint = currentRoom;
  currentRoom->printDescription();

  while (playing == true){
    cin.get(input,30);
    strToLower(input);
    
    if (firstWordCmp(input,"go")){
      Room* newRoom = currentRoom->getExit(input + 3);
      if (newRoom){
	currentRoom = newRoom;
	if (currentRoom->isEnd()){
	  cout << "You are on the highest point in the undead burg, the bell tower" << endl;
          cout << "You ring the church bells, signaling the first part of your journey is over. \n but this games scope is small \n so its over right now. \n good job. \n YOU WIN" << endl;
          playing = false;
        }
	else{
	  if(currentRoom->isCheckpoint())
	    currentCheckpoint = currentRoom;
	  currentRoom->printDescription();
	  if (currentRoom->combat( inventory)){
	    cout << "You were killed. You return to the last bonfire" << endl;
	    currentRoom = currentCheckpoint;
	  currentRoom->printDescription();
	  }
	}
      }
      else{
	cout << "You can't go " << (input + 3) << endl;
      }
    }
    else  if (firstWordCmp(input,"get")){
      currentRoom->takeItem(&inventory,input +4);
    }
    else if (firstWordCmp(input,"drop")){
      currentRoom->putItem(&inventory, input + 5);
    }
    else if (firstWordCmp(input,"inventory")){
      bool haveItems = false;
      for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	cout << (*it)->getName();
	haveItems = true;
      }
      if (!haveItems)
	cout << "You dont have anything" << endl;
    }
    else if (firstWordCmp(input,"help")){
      currentRoom->printDescription();
    }
    else if (firstWordCmp(input,"quit")){
      playing = false;
    }
    else{
      cout << "I dont know what you mean" << endl;
      cin.clear();
    }
    cin.ignore();
  }
  for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
    delete *it;
  }
  for(vector<Room*>::iterator it = roomList.begin(); it != roomList.end(); it++){
    delete *it;
  }
}
bool firstWordCmp(char* a, const char* b){ //checks to see if the first part of the longer word matches the short one
  for(int i = 0; i < strlen(b); i++){
    if (a[i] != b[i])
      return false;
  }
  return true;
}
void strToLower(char* a){ //converts words to lower
  while(*a){
    *a = tolower(*a);
    a++;
  }
}
