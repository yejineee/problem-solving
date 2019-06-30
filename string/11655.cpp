#include <iostream>
#include <string>
#include <ctype.h>
using namespace std ;
int main(){
  string s ; 
  getline(cin, s) ; 
  for(int i = 0 ; i < s.length() ; i++){
    if(islower(s[i])){
      if(s[i]+13 > 122){
        s[i] = 96 + ((s[i]+13)-122) ; 
      }else{
        s[i] = s[i] + 13 ; 
      }
    }
    else if(isupper(s[i])){
      if(s[i]+13 > 90){
        s[i] = 64 + ((s[i]+13)-90) ; 
      }else{
        s[i] = s[i] + 13 ; 
      }
    }
  }
  cout << s << endl ; 
  return 0 ; 
}