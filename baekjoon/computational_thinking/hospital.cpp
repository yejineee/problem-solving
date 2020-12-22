#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
using namespace std ;
typedef unsigned long long ull ;
map <ull, int> input ; // ( building , people ) 
map < ull, ull > from_building ; // (building, sum) ;
ull MAX = 0;
int N, K ;
void
find_max () {
  map <ull, int>::iterator prev ;
  map <ull, int>::iterator last_chk = input.begin() ;
  ull distance, building ;
  for(map <ull, int>::iterator it = input.begin() ; it != input.end() ; it++ ){
    building = it->first ;
    distance = building + 2*K ;

    if(it == input.begin())
      from_building[building] = 0 ;
    else 
      from_building[building] = from_building[prev->first] - input[prev->first] ;
    
    while(last_chk != input.end() && last_chk->first <= distance){
      from_building[building] += last_chk->second ;
      last_chk++ ;
    }
    MAX = max(MAX, from_building[building]) ;

    if(last_chk == input.end()) break ;
    else prev = it ;
  }
}


int 
main () {
  ull building ;
  int people ;
  cin >> N >> K ;
  for(int i = 0 ; i < N ; i++){
    cin >> people >> building ;
    input[building] = people ;
  }
  find_max() ;
  cout << MAX ;
}