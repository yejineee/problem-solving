#include <iostream>
#include <algorithm>
#include <climits>
#include <string.h>
using namespace std ; 
 
const int MAX_N = 1000 ; 

int N ;
int cost[MAX_N+1][3] ;
int sum_cost[MAX_N+1][3] ; 

void find_minCost(int color, int house){
  if(house == N){
    return ; 
  }
  for(int i = -2 ; i <= 2 ; i++){
    if(i == 0) continue ; 
    if(color+i >= 0 && color+i <= 2){
      if(sum_cost[house][color] + cost[house+1][color+i] < sum_cost[house+1][color+i]){
        sum_cost[house+1][color+i] = sum_cost[house][color] + cost[house+1][color+i] ; 
        find_minCost(color+i, house+1) ; 
      }
    }
  }
}

int main(){
  int r_cost, g_cost, b_cost ; 
  int final_cost[3] ;
  int min_cost ; 
  scanf("%d", &N) ; 
  for(int r = 1; r <= N ; r++){
    scanf("%d %d %d", &r_cost, &g_cost, &b_cost) ;
    cost[r][0] = r_cost ; 
    cost[r][1] = g_cost ; 
    cost[r][2] = b_cost ; 
  }

  for(int r = 2 ; r <= N ; r++){
    for(int c = 0 ; c <= 2 ; c++){
      sum_cost[r][c] = INT_MAX ; 
    }
  }
  for(int c = 0 ; c <= 2 ; c++){
    sum_cost[1][c] = cost[1][c] ; 
  }
  for(int color = 0 ; color <= 2 ; color++){
    find_minCost(color, 1) ; 
  }

  memcpy(final_cost, sum_cost+N,sizeof(int)*3) ;
  min_cost = *min_element(final_cost, final_cost+3) ;  
  printf("%d\n", min_cost) ;

}