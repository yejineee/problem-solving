#include <iostream>
#include <vector>

using namespace std ;

int count_stairs(int count){
  int sum_stairs = 0 ;
  vector<int> current (10,1);
  current[0] = 0 ;
  count -= 1 ; 

  while(count--){
    vector<int> next (10,0) ;
    for(int i = 0 ; i < 10 ; i++){
      if(i-1 >= 0){
        next[i-1] = (next[i-1]+current[i]) % 1000000000 ; 
      }
      if(i+1 < 10){
        next[i+1] = (next[i+1]+current[i]) % 1000000000 ; 
      }
    } 
    current.swap(next) ; 
  }
  for(int i = 0 ; i < 10 ; i++){
    sum_stairs = (sum_stairs + current[i]) % 1000000000; 
  }
  return sum_stairs ; 
}

int main(){
  int N ; 
  scanf("%d", &N) ; 
  printf("%d", count_stairs(N)) ; 
  return 0 ;
}