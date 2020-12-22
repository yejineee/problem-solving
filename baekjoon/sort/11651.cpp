#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std ; 
int N ; 
typedef vector<pair<int,int> > LOCATION ;
LOCATION::iterator it ; 
LOCATION l ;  

struct myclass{
  bool operator() (pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
      return (a.first < b.first) ; 
    }
    else{
      return (a.second < b.second) ; 
    }
  }
}mysort ;
int main(){
  int x, y ;
  scanf("%d", &N) ;
  while(N--){
    scanf("%d %d", &x, &y) ; 
    l.push_back(make_pair(x, y)) ; 
  }
  sort(l.begin(), l.end(), mysort) ; 
  for(it = l.begin() ; it != l.end() ; it++){
    printf("%d %d\n",(*it).first, (*it).second) ;
  }
  return 0 ;
}