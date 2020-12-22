#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std ; 
#define CARD long long
#define COUNT long long
typedef pair<CARD, COUNT> MIN;

int main(){
  map<CARD, COUNT> mymap;
  MIN min_v = make_pair(-1,-1);
  int N ;
  long long in ;
  scanf("%d",&N) ; 
  while(N--){
    scanf("%lld",&in) ; 
    if(mymap.find(in) == mymap.end()){
      mymap[in] = 1 ; 
    }else{
      mymap[in]++ ; 
    }
    if(min_v.first == -1){
      min_v = make_pair(in, mymap[in]) ;
    }
    else if(min_v.second < mymap[in]){
      MIN tmp = make_pair(in, mymap[in]) ;
      min_v.swap(tmp); 
    }
    else if(min_v.second == mymap[in] && min_v.first > in){
      MIN tmp = make_pair(in, mymap[in]) ;
      min_v.swap(tmp); 
    }
  }

  printf("%lld\n",min_v.first) ;
  return 0 ;
}