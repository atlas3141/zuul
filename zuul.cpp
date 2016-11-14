# include <iostream>
# include <cstring>
# include "Room.h"
# include "Item.h"

using namespace std;

bool firstWordCmp(char* a, const char* b);
void strToLower(char* a);

int main(){
  char input[30];
  bool playing = true;
  while (playing = true){
    cin >> input;
    strToLower(input);
    if (firstWordCmp(input,"go")){

    }
    if (firstWordCmp(input,"get")){

    }
    if (firstWordCmp(input,"drop")){

    }
    if (firstWordCmp(input,"inventory")){

    }
    if (firstWordCmp(input,"help")){

    }
    if (firstWordCmp(input,"quit"))
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
