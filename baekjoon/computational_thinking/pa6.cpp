#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std ;
const int MAX_IN = 100000 ; 
const int LESS = 1 ; 
const int MORE_EQUAL = 2 ; 

int poles[MAX_IN+1] ;
int N, K ; 

int count_amplifier(int test_min){
  int count = 1 ; 
  int current = 1 ;

  for(int next = current+1 ; next <= N ; next++){
    if(count > K)  return MORE_EQUAL ; 

    int dist = poles[next] - poles[current] ; 
    if(dist >= test_min){
      count += 1 ; 
      current = next ; 
    }
  }
  if(count >= K) return MORE_EQUAL ; 
  else return LESS ; 

}
int find_min_dist() {
  int test_dist, lower_bound, upper_bound ; 
  lower_bound = 1 ; 
  upper_bound = poles[N] - poles[1] ;
  int adj_K = K-2 ; 
  int partition = adj_K + 1 ;
  test_dist = upper_bound / partition ; 
  do{
    int flag = count_amplifier(test_dist) ; 
    switch(flag){
      case MORE_EQUAL:
        lower_bound = test_dist + 1 ; 
        break ;  
      case LESS : 
        upper_bound = test_dist - 1  ;
        break ; 
    }
    test_dist = (upper_bound + lower_bound) / 2 ; 
  }while(lower_bound <= upper_bound) ; 

  return upper_bound  ; 
}

int main(){
  scanf("%d %d", &N, &K) ; 
  for(int i = 1 ; i <= N ; i++){
    scanf("%d", &poles[i]) ;
  }

  sort(poles+1, poles+N+1) ;

  if(K==2){
    printf("%d", poles[N] - poles[1]) ; 
    return 0 ;
  }

  printf("%d", find_min_dist()) ; 
  return 0 ; 
}