#include <iostream> 
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <climits>
#include <unistd.h>

using namespace std ; 

const int MAX_N = 100000 ; 
int path[MAX_N+1][MAX_N+1] ;  
int degree[MAX_N+1] ;
int N, src ;  

void debug(){
  for(int c = 1 ; c <= N ; c++){
    for(int r = 1 ; r <= N ; r++){
      printf("%4d", path[c][r]) ; 
    }
    printf("\n") ; 
  }
  printf("\n") ; 
}
void find_pathLength(int v, bool visit[MAX_N+1]){
  printf("---- %d ----\n", v) ; 
  //sleep(1) ;
  visit[v] = true;  
  for(int dst = 1 ; dst <= N ; dst++){
    if(visit[dst] == false && path[v][dst] == 0){
      for(int internal = 1  ; internal <= N ; internal++){
        if(visit[internal] == false && degree[internal] >= 3){
          if(path[internal][dst] == 0){
            bool new_visit[MAX_N+1] ; 
            memset(new_visit+1, 0, N) ; 
            find_pathLength(internal, new_visit) ; 
            debug(); 
          }
          if(path[v][dst] == 0 || path[v][dst] > path[v][internal] + path[internal][dst]){
            path[v][dst] = path[v][internal] + path[internal][dst] ;
            path[dst][v] = path[v][internal] + path[internal][dst] ;            
          }
        }
      }
    }
  }
}

int main(){
  int a, b, l, total = 0 ;
  bool visit[MAX_N+1] ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N-1 ; i++){
    scanf("%d %d %d", &a, &b, &l) ;
    path[a][b] = l ; 
    path[b][a] = l ; 
    degree[a] += 1 ; 
    degree[b] += 1 ; 
  }

  for(int v = 1 ; v <= N ; v++){
      printf("========== %d =========\n", v) ; 
      memset(visit+1, 0, N) ; 
      find_pathLength(v, visit) ;
      debug() ; 
  }
  for(int c = 1 ; c <= N-1 ; c++){
    for(int r = c+1 ; r <= N ; r++){
      if(degree[r] < 3  && degree[c] < 3){
        printf("%d - %d : %d\n", c, r, path[c][r]) ; 
        total += pow(path[c][r], 2) ; 
      }
    }
  }
  printf("%d", total) ;
  return 0 ;
}
/*
1 - 5 : 24
1 - 6 : 25
1 - 7 : 22
1 - 8 : 23
1 - 10 : 17
5 - 6 : 5
5 - 7 : 10
5 - 8 : 11
5 - 10 : 21
6 - 7 : 11
6 - 8 : 12
6 - 10 : 22
7 - 8 : 3
7 - 10 : 19
8 - 10 : 20
*/