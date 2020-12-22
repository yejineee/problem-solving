// 프로그래머스 고득점 kit - dfs/bfs 네트워크
// https://programmers.co.kr/learn/courses/30/lessons/43162
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 200 ; 
bool check[MAX_N] ;

void follow_link(int cmp, vector<vector<int>> computers){
  check[cmp] = true ; 
  for(int next = 0 ; next < computers[cmp].size(); next++){
    if(computers[cmp][next] && !check[next] && next != cmp){
      follow_link(next, computers) ;
    }
  }
}
int solution(int n, vector<vector<int>> computers) {
  int network = 0 ; 

  for(int cmp = 0 ; cmp < n ; cmp++){
    if(!check[cmp]){
      network++ ; 
      follow_link(cmp, computers) ; 
    }
  }
  return network ; 
}