#include <iostream>
using namespace std ; 
#define VISIT 1
int P ;
int cycle ; 
int adj[2][1001] ;
int visit[1001] ; 
void check(int u){
  visit[u] = VISIT ; 
  if(visit[adj[1][u]] != VISIT){
    check(adj[1][u]) ; 
  }else{
    cycle++ ; 
    return ; 
  }
}
int main(){
  int T ; 
  scanf("%d",&T) ; 
  while(T--){
    scanf("%d",&P) ; 
    fill(visit,visit+P+1, 0) ; 
    for(int i = 1 ; i <= P ; i++){
      adj[0][i] = i ;
      scanf("%d",&adj[1][i]) ; 
    }
    cycle = 0 ; 
    for(int i = 1 ; i <= P ; i++){
      if(visit[i] != VISIT){
        check(i);
      }
    }
    printf("%d\n",cycle) ;
  }
}