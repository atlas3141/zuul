# include <iostream>
# include <cstring>

using namespace std;

bool firstWordCmp(char* a, const char* b);
void strToLower(char* a);

int main(){
  char input[30];
  cin >> input;
  strToLower(input);
  cout << input << endl;
  if (firstWordCmp(input,"fuck"))
    cout << "Penis" << endl;
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
