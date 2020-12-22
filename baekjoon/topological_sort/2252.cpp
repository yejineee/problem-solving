#include <iostream>
#include <vector>
#include <queue>
using namespace std ; 

const int MAX_N = 32000 ; 
priority_queue <int, vector<int>, greater<int> > pq; 
int indegree[MAX_N+1] ;
vector<int> edge[MAX_N+1] ;
int N ; 
int main(){
  int M ; 
  scanf("%d %d", &N, &M) ; 
  while(M--){
    int a, b ; 
    scanf("%d %d", &a, &b) ; 
    indegree[b] += 1 ; 
    edge[a].push_back(b) ; 
  }
  for(int i = 1 ; i <= N ; i++){
    if(indegree[i] == 0){
      pq.push(i) ; 
    }
  }
  while(!pq.empty()){
    int root = pq.top() ; 
    pq.pop() ; 
    printf("%d ", root) ; 

    for(vector<int>::iterator it = edge[root].begin() ; it != edge[root].end() ; it++){
      int u = *it ; 
      indegree[u] -= 1 ; 
      if(indegree[u] == 0){
        pq.push(u) ;
      }
    }
  }
}