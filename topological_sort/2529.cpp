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
  for(int i = 1 ; i <= K+1 ; i++){
    input.push_back(SIGN[i]) ;
    if(input.back() == '<')
      continue ;
    else if(input.back() == '>' || (i == K+1 && input.size() > 0)){
      string tmp ;
      while(input.size()){ 
        tmp = to_string(max_n) + tmp ;
        max_n -= 1 ;
        input.pop_back() ;
      }
      s += tmp ;
    }
  }

  cout << s << '\n';
}
void 
find_min() {
  string s ; 
  vector<char> input ;
  int max_n = K ;
  for(int i = K ; i >= 0 ; i--){
    input.push_back(SIGN[i]) ;
    if(input.back() == '>')
      continue ;
    else if(input.back() == '<' || (i == 0 && input.size() > 0)){
      string tmp ;
      while(input.size()){ 
        tmp += to_string(max_n) ;
        max_n -= 1 ;
        input.pop_back() ;
      }
      s = tmp + s ;
    }
  }
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