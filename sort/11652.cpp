#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std ; 
#define CARD long long
#define COUNT long long
typedef vector<pair<CARD, COUNT> > MIN;
map<CARD, COUNT> mymap;
MIN min_v ;  
vector<pair<CARD, COUNT> >::iterator it ; 
struct myclass{
  bool operator()(pair<CARD, COUNT> a, pair<CARD, COUNT> b){
    return (a.first < b.first) ; 
  }
}mysort ;
int main(){
  int N ;
  long long in ;
  scanf("%d",&N) ; 
  while(N--){
    scanf("%lld",&in) ; 
    if(mymap.find(in) == mymap.end()){//initial
      mymap[in] = 1 ; 
    }else{
      mymap[in]++ ; 
    }
    if(!min_v.size()){
      min_v.push_back(make_pair(in, mymap[in])) ;
    }
    else if(min_v.front().second < mymap[in]){
      min_v.clear();
      min_v.push_back(make_pair(in, mymap[in])) ; 
    }
    else if(min_v.front().second == mymap[in]){
      min_v.push_back(make_pair(in, mymap[in])) ;
    }
  }

  long long ret = min_v.front().first ; 
  sort(min_v.begin(), min_v.end(), mysort) ; 
  printf("%lld\n",min_v.front().first) ;
  return 0 ;
}