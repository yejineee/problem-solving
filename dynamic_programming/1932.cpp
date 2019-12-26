#include <iostream>
#include <algorithm>
#include <climits>
using namespace std ; 
const int MAX_NODE = 500*501/2 ; 
int triangle[MAX_NODE+1] ; 
int cum_sum[MAX_NODE+1] ;
int N ;
void cumulative_sum(){
  int node = 1, num_of_nodes ; 

  for(int level = 1 ; level < N ; level++){
    num_of_nodes = level ;
    while(num_of_nodes){
      int left = node + level ; 
      int right = left + 1 ;
      cum_sum[left] = max(cum_sum[left], cum_sum[node] + triangle[left]) ; 
      cum_sum[right] = max(cum_sum[right], cum_sum[node] + triangle[right]) ; 
      num_of_nodes -= 1 ;
      node += 1 ;
    }
  }
}
int main(){
  scanf("%d", &N) ; 
  int total_nodes = N*(N+1)/2 ;
  for(int i = 1 ; i <= total_nodes ; i++){
    scanf("%d", &triangle[i]) ; 
  }
  cum_sum[1] = triangle[1] ;
  cumulative_sum() ; 
  printf("%d", *max_element(cum_sum+total_nodes+1-N, cum_sum+total_nodes+1)) ; 
}
