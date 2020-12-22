#include <iostream>
using namespace std ;
const int MAX = 30 ;
bool INVALID = false ;
char br[MAX+1] ; 

bool
check_invalid(char s, char e){
    if(!(s == '(' && e == ')')  && !(s == '[' && e == ']')) return true ; 
    return false ;
}
int
compute (int start, int end) {
  int open = 0, ret = 0 ;
  int s, e ;
  for(int i = start ; i <= end ; i++){
    if(open < 0){
      INVALID = true ;
      break ;
    }
    if(br[i] == '(' || br[i] == '['){ 
      open += 1 ;
      if(open == 1) s = i ;
    }
    else if((br[i] == ')' || br[i] == ']')){
      if(open == 1){
        e = i ;
        if(check_invalid(br[s], br[e])){
          INVALID = true ;
          break ;
        }
        if(s+1 < e-1 ){
          if(br[i] == ')') ret += 2 * compute(s+1, e-1) ;
          else if(br[i] == ']') ret += 3 * compute(s+1, e-1) ;
        }
        else{
          if(br[i] == ')') ret += 2 ;
          else if(br[i] == ']') ret += 3 ;
        }
        open = 0 ;
      }
      else open -= 1 ;
    }
  }
  if(open != 0) INVALID = true ;
  if(INVALID) return 0 ;
  return ret ; 
} 
int 
main () {
  int idx ;
  for(idx = 1 ; idx <= 30 ; idx++){
    scanf("%c", &br[idx] ) ;
    if(br[idx] == '\n') break ;
  }
  printf("%d\n",compute(1, idx-1)) ;
  return 0 ;
}