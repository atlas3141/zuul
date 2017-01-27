#ifndef ITEM_H
#define ITEM_H
//items class that holds some basic stuff about the item
class Item{
 private:
  char* name;
  int powerLevel;
 public:
  Item(const char* newName, int newPowerLevel);
  ~Item();
  int getPowerLevel();
  char* getName();
};

#endif
