#include <iostream>
#include <utility>
#include <list>
#include <string.h>
using namespace std ;
const int MAXLEN = 50 ;
const int U = -1 ;
typedef int y ;
typedef int x ;

int Y, X ; 
char map[MAXLEN+1][MAXLEN+1] ;
int _map[MAXLEN+1][MAXLEN+1] ;
list<pair<y, x> > Q ;
int max_len ;


void
go () {
  int num = 0;
  while(Q.size()){
    int y = Q.front().first ;
    int x = Q.front().second ;
    num = _map[y][x] ;
    Q.pop_front() ;

    if(x < X && map[y][x+1] != 'W' && _map[y][x+1] == U ){ // RIGHT
      _map[y][x+1] = num+1 ;
      Q.push_back(make_pair(y,x+1)) ;
    }
    if(x > 1 && map[y][x-1] != 'W' && _map[y][x-1] == U ){ // LEFT
      _map[y][x-1] = num+1 ;
      Q.push_back(make_pair(y,x-1)) ;
    }
    if(y > 1 && map[y-1][x] != 'W' && _map[y-1][x] == U ){ // UP
      _map[y-1][x] = num+1 ;
      Q.push_back(make_pair(y-1,x)) ;
    }
    if(y < Y && map[y+1][x] != 'W' && _map[y+1][x] == U){ // DOWN
      _map[y+1][x] = num+1 ;
      Q.push_back(make_pair(y+1,x)) ;
    }
    
    max_len = max(max_len, num) ;
  }
}

int
main () {
  scanf("%d %d", &Y, &X) ;
  for(int y = 1 ; y <= Y ; y++){
    scanf("%s", map[y]+1) ;
  }
  for(int y = 1; y <= Y ; y++){
    for(int x = 1 ; x <= X ; x++){
      if(map[y][x] == 'L'){
        memset(_map,-1,sizeof(_map)) ;
        Q.push_back(make_pair(y,x)) ;
        _map[y][x] = 0 ;
        go() ;
      }
    }
  }

  printf("%d\n",max_len) ;
  return 0 ;
}