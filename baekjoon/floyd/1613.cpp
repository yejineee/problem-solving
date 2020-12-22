#include <iostream>
#include <climits>
using namespace std ;

const int MAX_EVENT = 400 ; 
int relation[MAX_EVENT+1][MAX_EVENT+1] ; 
int n_event ;

void check_relation(){
  for(int k = 1 ; k <= n_event ; k++){
    for(int i = 1 ; i <= n_event ; i++){
      for(int j = 1 ; j <= n_event ; j++){
        if(relation[i][j] != INT_MAX) continue ; 
        if(relation[i][k] == INT_MAX || relation[k][j] == INT_MAX){
          continue ; 
        }
        relation[i][j] = 1 ; 
      }
    }
  }
}
int main(){
  int n_relation, s ;
  scanf("%d %d", &n_event, &n_relation) ;
  for(int r = 1 ; r <= n_event ; r++){
    for(int c = 1 ; c <= n_event ; c++){
      if(r == c) relation[r][c] = 0 ; 
      else relation[r][c] = INT_MAX ; 
    }
  } 
  while(n_relation--){
    int u, v ;
    scanf("%d %d", &u, &v) ; 
    relation[u][v] = 1 ; 
  }
  check_relation() ; 
  
  scanf("%d", &s) ; 
  while(s--){
    int A, B ; 
    scanf("%d %d", &A, &B) ;
    if(relation[A][B] == 1){
      puts("-1") ;
    }
    else if(relation[B][A] == 1){
      puts("1") ; 
    }
    else{
      puts("0") ; 
    }
  }
}