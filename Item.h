#ifndef ITEM_H
#define ITEM_H

class Item{
 private:
  char* name;
 public:
  Item(const char* newName);
  ~Item();
  char* getName();
};

#endif
