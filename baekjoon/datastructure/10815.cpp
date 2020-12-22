#include <iostream>
#include <set>
using namespace std ;

set<int> my_card ; 

int main(){
  int N, M ; 
  scanf("%d", &N) ;
  while(N--){
    int card ; 
    scanf("%d", &card) ; 
    my_card.insert(card) ; 
  }
  scanf("%d", &M) ; 
  while(M--){
    int card ; 
    scanf("%d", &card) ; 
    if(my_card.find(card) != my_card.end()){
      printf("1 ") ; 
    }
    else{
      printf("0 ") ; 
    }
  }
}