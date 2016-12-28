#ifndef ITEM_H
#define ITEM_H

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
