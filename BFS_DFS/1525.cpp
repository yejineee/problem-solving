#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std ;

set <string> visit ;
queue <pair<string, int> > Q ;
int move = -1 ;
typedef enum {
  UP = -3 ,
  LEFT = -1 ,
  RIGHT = 1 ,
  DOWN = 3
}DIRECTION ;

string next_string (string s, DIRECTION dir){
  int loc = s.find("0") ;
  char tmp = s[loc] ;
  s[loc] = s[loc+dir] ;
  s[loc+dir] = tmp ;
  return s ;
}
int solution (string in, int n){
  string s, next ;
  int num , loc ;
  Q.push(make_pair(in, n)) ;
  while(!Q.empty()){
    s = Q.front().first ;
    num = Q.front().second ;
    Q.pop() ;
    if(s.compare("123456780") == 0){
      return num ;
    }
    loc = s.find("0") ;
    if(loc%3 != 0){           // left
      next = next_string(s,LEFT) ;
      if(visit.find(next) == visit.end()){
        visit.insert(next) ;
        Q.push(make_pair(next, num+1)) ;
      }
    }
    if(loc%3 != 2){           // right
      next = next_string(s,RIGHT) ;
      if(visit.find(next) == visit.end()){
        visit.insert(next) ;
        Q.push(make_pair(next, num+1)) ;
      }
    }
    if(loc >= 3){           // up
      next = next_string(s,UP) ;
      if(visit.find(next) == visit.end()){
        visit.insert(next) ;
        Q.push(make_pair(next, num+1)) ;
      }
    }
    if(loc <= 5){           // down
      next = next_string(s,DOWN) ;
      if(visit.find(next) == visit.end()){
        visit.insert(next) ;
        Q.push(make_pair(next, num+1)) ;
      }
    }
  }
  return -1 ;
}

int main () {
  string input = "";
  int num ;
  for(int i = 0 ; i < 9 ; i++){
    scanf("%d",&num) ;
    input += to_string(num) ;
  }
  cout << solution(input, 0) ;
}

