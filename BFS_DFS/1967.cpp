#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std ; 
#define MAX_IN 10002
typedef int PARENT ; 
typedef int WEIGHT ; 
int N ; 
pair<PARENT, WEIGHT> EDGE[MAX_IN] ; 
int NODE_W[MAX_IN] ; 
int NODE_D[MAX_IN] ; 
int MAX_D = 0 ; 

void compute_weight(int n){
  int prev_w = NODE_W[EDGE[n].first] ; 
  NODE_W[EDGE[n].first] = max(NODE_W[EDGE[n].first], NODE_W[n]+EDGE[n].second) ;
  if(NODE_D[EDGE[n].first] == 0){
    NODE_D[EDGE[n].first] = NODE_W[EDGE[n].first] ; 
  }
  else{
    NODE_D[EDGE[n].first] = max(NODE_D[EDGE[n].first] , prev_w + NODE_W[n] + EDGE[n].second) ;
  }
  MAX_D = max(MAX_D, NODE_D[EDGE[n].first]) ; 
}

int main(){
  int p, c, w ; 
  scanf("%d", &N) ; 
 
  for(int i = 0 ; i < N-1 ; i++){
    scanf("%d %d %d", &p, &c, &w) ; 
    EDGE[c] = make_pair(p, w) ; 
  }
  for(int i = N ; i > 1 ; i--){
    compute_weight(i) ; 
  }
  printf("%d\n", MAX_D) ; 
  return 0 ;
}