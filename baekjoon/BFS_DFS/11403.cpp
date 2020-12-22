#include <iostream>
using namespace std ;

const int MAX = 100 ; 
int N ;
int m[MAX+1][MAX+1] ; 
int edge[MAX+1][MAX+1] ; 
bool visit[MAX+1][MAX+1] ; 

void check_edge(int s, int u){
  
  for(int i = 1 ; i <= N ; i++){
    if(m[u][i] && !visit[u][i]){
      visit[u][i] = true ; 
      edge[s][i] = 1 ; 
      if(s != i){
        check_edge(s, i) ; 
      }
    }
  }
}

void init_visit(){
  for(int r = 1 ; r <= N ; r++){
    for(int c = 1 ; c <= N ; c++){
      visit[r][c] = false ;
    }
  }
}

int main(){
  scanf("%d", &N) ; 

  for(int r = 1 ; r <= N ; r++){
    for(int c = 1 ; c <= N ; c++){
      scanf("%d", &m[r][c]) ;
    }
  }

  for(int i = 1 ; i <= N ; i++){
    init_visit() ; 
    check_edge(i, i) ; 
  }

  for(int r = 1 ; r <= N ; r++){
    for(int c = 1 ; c <= N ; c++){
      printf("%d ", edge[r][c]) ;
    }
    puts("") ; 
  }
  return 0 ;
}