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
  bool relax ;
  for(int i = 1 ; i <= n_branch ; i++){
    dist[i] = 1000000000 ; 
  }
  dist[start] = 0 ; 

  for(int i = 1 ; i <= n_branch ; i++){
    relax = false ; 
    for(int u = 1 ; u <= n_branch ; u++){
      for(it = road[u].begin() ; it != road[u].end() ; it++){
        int v = (*it).first ; 
        int time = (*it).second ; 
        if(dist[v] > dist[u] + time){
          dist[v] = dist[u] + time ; 
          relax = true ; 
        }
      }
    }
    if(!relax) return false ; 
  }

  return relax ; 
}

int main(){
  int T, wormhole, n_road ; 
  scanf("%d", &T) ; 
  while(T--){
    vector<pair<int, int> > road[MAX+1] ;
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
    if(is_time_back(road, 1))
      puts("YES") ;
    else puts("NO") ;
  }
  return 0 ;
}