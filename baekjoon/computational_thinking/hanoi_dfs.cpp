#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std ;

const int INF = 999999999 ;
const int n_rod = 3 ;
set<vector<vector<int> > > visit ;
int N, dest ;
int next_dir[4] = {-2, -1, 1, 2} ;
int min_move = INF ;
void print_rod(vector<vector<int> > rod, int move){
  printf("--------move : %d--------\n", move) ;
  for(int i = 0 ; i < n_rod ; i++){
    printf("[%d] ", i) ;
    for(vector<int>::iterator it = rod[i].begin() ; it != rod[i].end() ; it++){
      printf("%d ", *it) ;
    }
    printf("\n") ;
  }
  puts("---------------------") ;
}

int hanoi(vector<vector<int > > current, int move){
  if(move > min_move|| move > pow(2,N)-1 ) return INF ;
  print_rod(current, move) ;

  if(current[dest].size() == N){
    return move ;
  }
  for(int rod = 0 ; rod  < n_rod ; rod++){
    if(current[rod].empty()) continue ;
    vector<vector<int > > next;
    next.resize(3) ;
    for(int d = 0 ; d < 4 ; d++){
      int next_rod = rod + next_dir[d] ;
      if(next_rod >= 0 && next_rod < 3){
        for(int j = 0 ; j < n_rod ; j++){
          next[j] = current[j] ;
        }
        if(next[next_rod].empty()){
          next[next_rod].push_back(next[rod].back()) ;
          next[rod].pop_back() ;
          if(visit.find(next) == visit.end()){
            visit.insert(next) ;
            min_move = min(min_move, hanoi(next, move+1)) ;
          }
        }
        else if(!next[next_rod].empty() && next[rod].back() < next[next_rod].back()){
          next[next_rod].push_back(next[rod].back()) ;
          next[rod].pop_back() ;
          if(visit.find(next) == visit.end()){
            visit.insert(next) ;
            min_move = min(min_move, hanoi(next, move+1)) ;
          }
        }
      }
    }

  }
  return min_move ;
}
int main () {

  vector<vector<int > > rod ;
  rod.resize(3) ;
  scanf("%d %d", &N, &dest) ;
  dest -= 1 ;
  for(int i = 0 ; i < n_rod ; i++){
    int num, disk ;
    scanf("%d", &num) ; 
    while(num--){
      scanf("%d", &disk) ;
      rod[i].push_back(disk) ;
    }
  }
  printf("%d", hanoi(rod, 0)) ;
  return 0 ;
}
