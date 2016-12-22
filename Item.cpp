#include "Item.h"
#include "cstring"

Item::Item(const char* newName){
  name = strdup(newName);
}
Item::~Item(){
  delete name;
}
char* Item::getName(){
  return name;
}
