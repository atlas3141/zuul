# include <iostream>
# include <cstring>
# include <vector>
# include "Room.h"
# include "Item.h"
using namespace std;

bool firstWordCmp(char* a, const char* b);
void strToLower(char* a);

void roomSetup(vector<Room*>* roomList){
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
        
  new_londo_elevator->setExit("north",firelink_shrine);
}
int main(){
  vector<Item*> inventory;
  vector<Room*> roomList;
  Room* currentRoom;
  char input[30];
  bool playing = true;

  Item* item1 = new Item("sword");

  roomSetup(&roomList);
  currentRoom = *roomList.begin();
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
