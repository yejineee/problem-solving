#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std ;
int K ;
char SIGN[10] ;

void 
find_max() {
  string s ; 
  vector<char> input ;
  int max_n = 9 ;
  for(int i = 1 ; i <= K ; i++){
    input.push_back(SIGN[i]) ;
    if(input.back() == '<')
      continue ;
    else if(input.back() == '>'){
      string tmp ;
      while(input.size()){ 
        tmp = to_string(max_n) + tmp ;
        max_n -= 1 ;
        input.pop_back() ;
      }
      s += tmp ;
    }
  }
  string tmp ;
  while(input.size()){
    tmp = to_string(max_n) + tmp ;
    max_n -= 1 ;
    input.pop_back() ;
  }
  tmp = to_string(max_n) + tmp ;
  s += tmp ;
  cout << s << '\n';
}
void 
find_min() {
  string s ; 
  vector<char> input ;
  int max_n = K ;
  for(int i = K ; i >= 1 ; i--){
    input.push_back(SIGN[i]) ;
    if(input.back() == '>')
      continue ;
    else if(input.back() == '<'){
      string tmp ;
      while(input.size()){ 
        tmp += to_string(max_n) ;
        max_n -= 1 ;
        input.pop_back() ;
      }
      s = tmp + s ;
    }
  }
  string tmp ;
  while(input.size()){
    tmp += to_string(max_n);
    max_n -= 1 ;
    input.pop_back() ;
  }
  tmp += to_string(max_n) ;
  s = tmp + s ;
  cout << s << '\n';
}

int 
main () {
  scanf("%d", &K) ;
  int idx = 1 ;
  char c ;
  while(idx <= K){
    scanf("%c", &c) ;
    if(c != ' ' && c != '\n'){
      SIGN[idx] = c ;
      idx += 1 ;
    }
  }

  find_max() ;
  find_min() ; 
  
}