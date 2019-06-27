#include <iostream>
#include <list>
#include <iterator> 
using namespace std ;
int M, N ; 
list<int> result ;

int main(){
  int testcase ;
  scanf("%d",&testcase) ; 

  while(testcase-- > 0){
    scanf("%d %d",&M,&N) ; 
    int GRID[M+1][N+1] ; 
    for(int y = 1 ; y < M+1 ; y++){
      for(int x = 1 ; x < N+1 ; x++){
        scanf("%d", &GRID[y][x]) ; 
      }     
    }
    
    int dist = 0;
    int fur_y , cur_y ; 
    for(int y = M ; y > 0 ; y--){
      for(int x = 1 ; x <= N ; x++){
        if(GRID[y][x] == 0) continue ; 
        else{
          cur_y = y ; 
          fur_y = y+1 ; 
          while(fur_y < M+1 && GRID[fur_y][x] == 0){
            GRID[cur_y][x] = 0 ; 
            GRID[fur_y][x] = 1 ; 
            dist++ ; 
            cur_y = fur_y;
            fur_y++ ;
          }
        }
      }
    }
    result.push_back(dist) ;

  }

  for(list<int>::iterator itr = result.begin() ; itr != result.end() ; itr++){
    printf("%d\n",*itr) ; 
  }

}