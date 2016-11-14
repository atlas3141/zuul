#ifndef ITEM_H
#define ITEM_H

class Item{
 private:
  char name[64];
 public:
  Item(const char* name);
  char* getName();
};

#endif
