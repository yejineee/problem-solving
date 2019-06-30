#include <iostream>
#include <list>
using namespace std ; 
int N, K ;
list<int> circle ;
list<int>::iterator it, it2 ; 

void erase(){
  cout << '<' ; 
  it = circle.begin() ; 
  while(circle.size() > 1){
    int count = K - 1 ; 
    while(count-- > 0){
      it++ ; 
      if(it == circle.end()){
        it = circle.begin() ; 
      } 
    }
    cout << *it << ", " ; 
    it = circle.erase(it) ;
    if( it == circle.end()){
      it = circle.begin() ; 
    }
  }
  cout << *it << '>' << endl ; 
  return ; 
}
int main(){
 
  scanf("%d %d", &N, &K) ; 
  for(int i = 1 ; i <= N ; i++){
    circle.push_back(i) ; 
  }
  erase() ; 
  return 0 ; 
}