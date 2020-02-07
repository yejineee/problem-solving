#include <iostream>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std ; 
const int MAX_N = 1000 ; 
int n_computer ;
vector<pair<int, int> > adj_list[MAX_N+1] ; 
int t_time[MAX_N+1] ; 
int connect[MAX_N+1] ; 

void find_min_time(){
  vector<bool> visit (n_computer+1, 0) ; 
  priority_queue<pair<int, int > > pq ; 
  fill(t_time+1, t_time+n_computer+1, INT_MAX) ; 
  t_time[1] = 0 ;
  pq.push(make_pair(-1 * (t_time[1]), 1)) ;

  while(!pq.empty()){
    int here = pq.top().second ; 
    int here_time = -1 * pq.top().first ; 
    pq.pop() ; 
    if(t_time[here] < here_time) continue ; 

    visit[here] = true ; 
    for(int i = 0 ; i < adj_list[here].size() ; i++){
      int there = adj_list[here][i].first ; 
      int there_time = adj_list[here][i].second ; 
      if(visit[there]) continue ; 
      if(t_time[there] > here_time + there_time){
        t_time[there] = here_time + there_time ; 
        connect[there] = here ; 
        pq.push(make_pair(-1 * t_time[there], there)) ; 
      }
    }
  }
} 

int main(){
  int n_line; 
  scanf("%d %d", &n_computer, &n_line) ; 
  for(int i = 0 ; i < n_line ; i++){
    int A, B, T ; 
    scanf("%d %d %d", &A, &B, &T) ; 
    adj_list[A].push_back(make_pair(B, T)) ; 
    adj_list[B].push_back(make_pair(A, T)) ; 
  }
  find_min_time() ; 
  
  printf("%d\n", n_computer-1) ; 
  for(int i = 2 ; i <= n_computer ; i++){
    printf("%d %d\n", i, connect[i]) ; 
  }
  return 0 ;
}