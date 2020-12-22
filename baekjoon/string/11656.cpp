#include <iostream>
#include <list>
#include <string>
using namespace std ; 

int main(){
  string s ;
  cin >> s ; 
  list<string> suffix ; 
  for(int i = 0; i < s.length() ; i++){
    suffix.push_back(s.substr(i)) ; 
  }
  suffix.sort() ;
  for(list<string>::iterator it = suffix.begin() ; it != suffix.end() ; it++){
    cout << *it << endl ; 
  }
  return 0 ;
}
