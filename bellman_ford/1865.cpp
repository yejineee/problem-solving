#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std ;

const int MAX = 500 ;
int dist[MAX+1] ; 
int n_branch ; 

bool is_time_back(vector<pair<int, int> > road[MAX+1], int start){
  vector<pair<int, int> >::iterator it ; 

  for(int i = 1 ; i <= n_branch ; i++){
    dist[i] = INT_MAX ; 
  }
  dist[start] = 0 ; 

  for(int i = 1 ; i <= n_branch-1 ; i++){
    bool relax = false ; 
    for(int u = 1 ; u <= n_branch ; u++){
      for(it = road[u].begin() ; it != road[u].end() ; it++){
        int v = (*it).first ; 
        int time = (*it).second ; 
        if(dist[u] != INT_MAX && dist[v] > dist[u] + time){
          dist[v] = dist[u] + time ; 
          relax = true ; 
        }

      }
    }
    if(!relax) return false ; 
  }

  for(int u = 1 ; u <= n_branch ; u++){
    for(it = road[u].begin() ; it != road[u].end() ; it++){
      int v = (*it).first ; 
      int time = (*it).second ;
      if(dist[u] != INT_MAX && dist[v] > dist[u] + time){
        return true ; 
      }
    }
  }

  return false ; 
}

int main(){
  int T, wormhole, n_road ; 
  scanf("%d", &T) ; 
  while(T--){
    vector<pair<int, int> > road[MAX+1] ;
    bool backward = false ; 
    scanf("%d %d %d", &n_branch, &n_road, &wormhole) ; 
    for(int i = 0 ; i < n_road ; i++){
      int u, v, time ; 
      scanf("%d %d %d", &u, &v, &time) ; 
      road[u].push_back(make_pair(v, time)) ; 
      road[v].push_back(make_pair(u, time)) ; 
    }
    for(int i = 0 ; i < wormhole ; i++){
      int u, v, time ; 
      scanf("%d %d %d", &u, &v, &time) ; 
      road[u].push_back(make_pair(v, -1 * time)) ; 
    }
    for(int s = 1 ; s <= n_branch ; s++){
      if(is_time_back(road, s)){
        backward = true ; 
        break ; 
      }
    }
    if(backward){
      puts("YES") ;
    }
    else puts("NO") ;
    // puts("==================") ;  
    // for(int i = 1 ; i <= n_branch ; i++){
    //   printf("%d] %d\n", i, dist[i]) ; 
    // }
  }
  return 0 ;
}