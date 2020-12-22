#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std ;
const int MAX_HOUSE = 100000 ; 
vector<pair<int, int > > path[MAX_HOUSE+1] ;
bool visit[MAX_HOUSE+1] ; 
int cost[MAX_HOUSE+1] ; 
int n_house ; 

int connect_house(){
  int sum_cost = 0, max_cost = 0, n_connect = 0; 
  priority_queue<pair<int, int> > q ; 
  q.push(make_pair(0, 1)) ; 
  for(int i = 2 ; i <= n_house ; i++){
    cost[i] = INT_MAX ; 
  }
  while(!q.empty()){
    int here = q.top().second ; 
    q.pop() ; 
    if(visit[here]) continue ; 

    n_connect += 1 ; 
    max_cost = max(max_cost, cost[here]) ; 
    sum_cost += cost[here] ; 
    visit[here] = true ; 
    if(n_connect == n_house) break ; 

    for(int i = 0 ; i < path[here].size() ; i++){
      int next = path[here][i].first ; 
      int next_cost = path[here][i].second ; 
      if(visit[next] == false && cost[next] > next_cost){
        cost[next] = next_cost ; 
        q.push(make_pair(-1 * cost[next], next)) ; 
      }
    }
  }
  return sum_cost - max_cost ; 
}
int main(){
  int n_path ; 
  scanf("%d %d", &n_house, &n_path) ; 
  while(n_path--){
    int A, B, c ; 
    scanf("%d %d %d", &A, &B, &c) ; 
    path[A].push_back(make_pair(B, c)) ; 
    path[B].push_back(make_pair(A, c)) ; 
  }
  printf("%d", connect_house()) ; 

  return 0 ;
}
