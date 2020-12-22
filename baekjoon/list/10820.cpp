#include <iostream>
#include <ctype.h>
#include <string>
#include <list>
using namespace std ; 
int main(){
  string s ;
  list<int> slower, supper, sdigit, sspace ; 
  int lower = 0, upper = 0, digit = 0, space = 0 ; 
  while(getline(cin, s)){
    lower = 0, upper = 0, digit = 0, space = 0 ;
    if(s.empty()) break ;
    for(int i = 0 ; i < s.length() ; i++){
      if(islower(s[i])){
        lower++ ; 
      }
      else if(isupper(s[i])){
        upper++ ; 
      }
      else if(isdigit(s[i])){
        digit++ ;
      }
      else if(s[i] == ' '){
        space++ ; 
      }
    }
    slower.push_back(lower) ; 
    supper.push_back(upper) ; 
    sdigit.push_back(digit) ; 
    sspace.push_back(space) ; 
  }
  while(!slower.empty()){
    printf("%d %d %d %d\n", slower.front(), supper.front(), sdigit.front(), sspace.front()) ; 
    slower.pop_front() ; 
    supper.pop_front() ; 
    sdigit.pop_front() ; 
    sspace.pop_front() ; 
  }

}