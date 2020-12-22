#include <iostream>
#include <vector>
using namespace std ;
const int MAX_COMPUTER = 100 ; 
vector<int> edge[MAX_COMPUTER+1] ; 
bool visit[MAX_COMPUTER+1] ; 
int connect = 0 ;

void count_connection(int v){
  visit[v] = true ;
  connect += 1 ; 
  for(vector<int>::iterator it = edge[v].begin() ; it != edge[v].end() ; it++){
    int next = *it ;
    if(visit[next] == false){
      count_connection(next) ; 
    }
  }
}
int main(){
  int n_computer, n_pair ; 
  scanf("%d %d", &n_computer, &n_pair) ; 
  for(int i = 0 ; i < n_pair ; i++){
    int v, w ; 
    scanf("%d %d", &v, &w) ; 
    edge[v].push_back(w) ; 
    edge[w].push_back(v) ; 
  }
  count_connection(1) ; 
  printf("%d", connect-1) ; 
}