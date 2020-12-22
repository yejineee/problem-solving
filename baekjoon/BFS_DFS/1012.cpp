#include <iostream>
#include <string.h>
#include <list>
#include <utility>
using namespace std ;
int N, M, CNT ;
const int MAX = 50 ; 
typedef int X ;
typedef int Y ;
list<pair<Y, X> > locat ;
int field[MAX][MAX] ;

void
check (int y , int x){
  field[y][x] = CNT ;
  if(x+1 < M && field[y][x+1] == -1){ check(y, x+1) ;} // right
  if(x-1 >= 0 && field[y][x-1] == -1){ check(y, x-1) ;} // left
  if(y+1 < N && field[y+1][x] == -1){ check(y+1, x) ;} // up
  if(y-1 >= 0 && field[y-1][x] == -1){ check(y-1, x) ;} // down
}
int 
main (){
  int T, K, x, y ;
  scanf("%d", &T) ;
  while(T--){
    memset(field,0,sizeof(field)) ;
    CNT = 0 ;
    list<pair<Y, X> > locat ;

    scanf("%d %d %d",&M, &N, &K) ;
    while(K--){
      scanf("%d %d", &x, &y) ;
      locat.push_back(make_pair(y, x)) ;
      field[y][x] = -1 ;
    }
    for(list<pair<Y, X> >::iterator itr = locat.begin() ; itr != locat.end() ; itr++){
      if(field[(*itr).first][(*itr).second] == -1){
        CNT += 1 ;
        check((*itr).first, (*itr).second) ;
      }
    }
    printf("%d\n",CNT) ;
  }
}