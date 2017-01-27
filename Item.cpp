#include "Item.h"
#include "cstring"
//Its an item class that holds some basic info about the items
Item::Item(const char* newName, int newPowerLevel){
  name = strdup(newName);
  powerLevel = newPowerLevel;
}
Item::~Item(){
  delete name;
}
char* Item::getName(){
  return name;
}
int Item::getPowerLevel(){
  return powerLevel;
}
