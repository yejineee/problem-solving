#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <math.h>
using namespace std ;

const int INF = 999999999 ;
const int n_rod = 3 ;
queue< pair<vector<vector<int > >, int > > Q; // prev, current, move
set<vector<vector<int> > > visit ;
int N, dest ;
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

int hanoi(vector<vector<int > > start, int move){
  Q.push(make_pair(start, move)) ;
  while(!Q.empty()){
    vector<vector<int > > current = Q.front().first ;
    int move = Q.front().second ;
    Q.pop() ;
    print_rod(current, move) ;

    if(current[dest].size() == N){
      return move ;
    }


  for(int i = 0 ; i < n_rod ; i++){
    if(current[i].empty()) continue ;
    vector<vector<int > > next;
    next.resize(3) ;
    if(i+1 < n_rod){
      for(int j = 0 ; j < n_rod ; j++){
          next[j] = current[j] ;
      }
      if(next[i+1].empty()){
          next[i+1].push_back(next[i].back()) ;
          next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
      }
      else if(!next[i+1].empty() && next[i].back() < next[i+1].back()){
          next[i+1].push_back(next[i].back()) ;
          next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
      }
    }
    if(i+2 < n_rod){
        for(int j = 0 ; j < n_rod ; j++){
            next[j] = current[j] ;
        }
        if(next[i+2].empty()){
            next[i+2].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
        else if(!next[i+2].empty() && next[i].back() < next[i+2].back()){
            next[i+2].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
    }
    if(i-1 >= 0){
        for(int j = 0 ; j < n_rod ; j++){
            next[j] = current[j] ;
        }
        if(next[i-1].empty()){
            next[i-1].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
        else if(!next[i-1].empty() && next[i].back() < next[i-1].back()){
            next[i-1].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
    }
    if(i-2 >= 0){
        for(int j = 0 ; j < n_rod ; j++){
            next[j] = current[j] ;
        }
        if(next[i-2].empty()){
            next[i-2].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
        else if(!next[i-2].empty() && next[i].back() < next[i-2].back()){
            next[i-2].push_back(next[i].back()) ;
            next[i].pop_back() ;
          if(visit.find(next) == visit.end()){
            Q.push(make_pair(next, move+1)) ;
            visit.insert(next) ;
          }
        }
    }
  }

  }
  return 0;
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
