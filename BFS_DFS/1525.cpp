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
typedef struct{
  int y, x;
}DIR ;

DIR next_dir[4] = {{1,0} , {-1,0}, {0,1}, {0,-1}} ;

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
    int y = loc / 3 ;
    int x = loc % 3 ;
    for(int i = 0 ;  i < 4 ; i++){
      int next_y = y + next_dir[i].y ;
      int next_x = x + next_dir[i].x ;
      if(next_y >= 0 && next_y < 3 && next_x >= 0 && next_x < 3){
        string temp = s ;
        swap(temp[loc], temp[3*next_y + next_x]) ;
        if(visit.find(temp) ==  visit.end()){
          visit.insert(temp) ;
          Q.push(make_pair(temp, num+1)) ;
        }
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

