  #include <iostream>
  #include <vector>
  #include <utility>
  #include <queue>
  using namespace std ; 
  const int MAX_V = 1000 ; 
  const int INF = 1000000000 ; 
  // 정점의 개수
  int V, E;

vector<pair<double, in
t> > adj[MAX_V];
vector<double> dist(MAX_V, 0);

void dijkstra(int src) {

  dist[src] = 0 ;
  priority_queue<pair<double, int> > pq;
  pq.push(make_pair(1, src));

  while (!pq.empty()) {
    int here = pq.top().second;
    double cost = pq.top().first;
    pq.pop();
    printf("--------- %d -------\n", here) ; 
      for(int i = 1 ; i <= V ; i++){
        printf("[%d] %.3lf -> ", i, dist[i]) ; 
      }
      printf("\n") ; 
    if (dist[here] > cost) continue;

    for (int i = 0; i < adj[here].size(); ++i) {
    
      int there = adj[here][i].second;
      double nextDist = cost * adj[here][i].first;
      if (dist[there] < nextDist) {
        printf("%d ] %.3lf -> %.3lf\n", there, dist[there], nextDist) ; 
        dist[there] = nextDist;
        pq.push(make_pair(nextDist, there));
      }
    }
  }

  return ;
}

int main(){
  scanf("%d %d", &V, &E) ;
  for(int i = 0 ; i < E ; i++){
    int src, dst ;
    double p, not_p ; 
    scanf("%d %d %lf", &src, &dst, &p) ;
    not_p = 1 - p ;
    if(p != 1)
      adj[src].push_back(make_pair(not_p, dst)) ;
    
  }

  dijkstra(1) ;
  for(int i = 1 ; i <= V ; i++){
    printf("[%d] %.3lf -> ", i, dist[i]) ; 
  }
}