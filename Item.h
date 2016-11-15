#ifndef ITEM_H
#define ITEM_H

class Item{
 private:
  char* name;
 public:
  Item(char* newName);
  char* getName();
};

#endif
