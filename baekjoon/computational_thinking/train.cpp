#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX_N = 40000 ;
int p, q, r, N, M ;
int INF = 2147438647;

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; 
vector<pair<int,int> > alpha[MAX_N];  
vector<pair<int,int> > beta[MAX_N];  
vector<pair<int,int> > link[MAX_N];  
int dist_from_alpha[MAX_N+1] ;
int dist_from_beta [MAX_N+1];
int dist_from_link [MAX_N+1];
int min_link = INF ;


void dijkstra(int start, int dist[MAX_N+1], vector<pair<int,int> > adj[MAX_N]) {
	dist[start] = 0 ;
	pq.push(make_pair(start, 0)) ; 

	while(!pq.empty()) {
		int current = pq.top().first ;
		int distance = pq.top().second;
		pq.pop();

		if(dist[current] < distance) continue;

		for(int i = 0; i < adj[current].size(); i++) {
			int next = adj[current][i].first ; 

			if(distance + adj[current][i].second < dist[next]) {
				dist[next] =  distance + adj[current][i].second ;
				pq.push(make_pair(next, dist[next])) ;
			}
		}
	}
}

void init_dist(int d[MAX_N+1]){
  for(int i = 1 ; i <= N ; i++){
    d[i] = INF ;
  }
}
int main(void) {
 int u, v ;
  scanf("%d %d %d %d %d",&p, &q, &r, &N, &M) ;
  for(int i = 0 ; i < M ; i++){
    scanf("%d %d", &u, &v) ;
	  alpha[u].push_back(make_pair(v, p));
	  alpha[v].push_back(make_pair(u, p));
	  beta[u].push_back(make_pair(v, q));
	  beta[v].push_back(make_pair(u, q));
    link[u].push_back(make_pair(v, r));
	  link[v].push_back(make_pair(u, r));
  }

  init_dist(dist_from_alpha) ;
  init_dist(dist_from_beta) ;
  init_dist(dist_from_link) ;

	dijkstra(1, dist_from_alpha, alpha);
	dijkstra(2, dist_from_beta, beta);
  dijkstra(N, dist_from_link, link) ;

  for(int i = 1 ; i <= N ; i++){
    min_link = min(min_link, dist_from_alpha[i] + dist_from_beta[i] + dist_from_link[i]) ;
  }
  printf("%d",min_link) ;
}
