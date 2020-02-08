#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std ; 
const int MAX_CITY = 1000 ; 
vector<pair<int, int> > bus[MAX_CITY+1] ; 
int n_city ; 

int find_min_cost(int start, int end){
  priority_queue<pair<int, int> > pq ; 
  int dist [MAX_CITY+1] ; 
  fill(dist+1, dist+n_city+1, INT_MAX ) ;

  dist[start] = 0 ;
  pq.push(make_pair(0, start)) ; 
  
  while(!pq.empty()){
    int here = pq.top().second ; 
    int here_dist = pq.top().first * (-1); 
    pq.pop() ; 
    if(here_dist > dist[here]) continue ; 
    
    for(int i = 0 ; i < bus[here].size() ; i++){
      int there = bus[here][i].first ; 
      int cost = bus[here][i].second ; 
      if(dist[there] > here_dist + cost){
        dist[there] = here_dist + cost ; 
        pq.push(make_pair(-1 * dist[there], there)) ; 
      }
    }
    if(here == end) break ; 
  }
  return dist[end] ; 
}
int main(){
  int n_bus, departure, destination ; 
  scanf("%d %d", &n_city, &n_bus) ; 
  while(n_bus--){
    int A, B, cost ; 
    scanf("%d %d %d", &A, &B, &cost) ; 
    bus[A].push_back(make_pair(B, cost)) ; 
  }
  scanf("%d %d", &departure, &destination) ; 
  printf("%d",find_min_cost(departure, destination)); 
  return 0 ; 
}

