#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

const int  MAX_N = 1000 ; 
vector<int> dist[MAX_N+1] ;
int V ; 

void find_shortest_path(){
  for(int k = 1 ; k <= V ; k++){
    for(int i = 1 ; i <= V ; i++){
      for(int j = 1 ; j <= V ; j++){
        if(i == j || dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue ; 
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ; 
      }
    }
  }
}


int main(){
  int E, party ;
  int longest = 0 ;
  scanf("%d %d %d", &V, &E, &party) ; 
  for(int i = 1 ; i <= V ; i++){
    dist[i].assign(V+1, INT_MAX) ; 
    dist[i][i] = 0 ;
  }

  for(int i = 0 ; i < E ; i++){
    int start, end, time ;
    scanf("%d %d %d", &start, &end, &time) ; 
    dist[start][end] = time ;
  }

  find_shortest_path() ; 
  for(int u = 1 ; u <= V ; u++){
    longest = max(longest, dist[u][party] + dist[party][u]) ; 
  }
  printf("%d", longest) ; 
  return 0 ; 
}

