#include <iostream>
using namespace std ;

const int MAX = 100 ; 
int N ;
int edge[MAX+1][MAX+1] ; 
int start ;

void check_edge(){
  for(int k = 1 ; k <= N ; k++){
    for(int x = 1 ; x <= N ; x++){
      for(int y = 1 ; y <= N ; y++){
        if(edge[x][k] && edge[k][y])
          edge[x][y] = 1 ; 
      }
    }
  }
}

int main(){
  scanf("%d", &N) ; 

  for(int r = 1 ; r <= N ; r++){
    for(int c = 1 ; c <= N ; c++){
      scanf("%d", &edge[r][c]) ;
    }
  }

  for(int r = 1 ; r <= N ; r++){
    for(int c = 1 ; c <= N ; c++){
      printf("%d ", edge[r][c]) ;
    }
    puts("") ; 
  }
  return 0 ;
}