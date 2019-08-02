#include <iostream>
#include <math.h>
using namespace std ;

int
in_planet (int x1, int y1, int x2, int y2, int cx, int cy, int r){
  int cnt = 0 ;
  if( pow(x2-cx, 2) + pow(y2-cy,2) < pow(r,2)){
    cnt += 1;
  }
  if( pow(x1-cx, 2) + pow(y1-cy,2) < pow(r,2)){
    cnt += 1;
  }
  if(cnt == 2) return 0 ;
  return cnt ;
}

int 
main (){
  int T , N ;
  int sx,sy,fx,fy,cx,cy,r ;
  int count ;
  scanf("%d", &T) ;
  while(T--){
    scanf("%d %d %d %d %d", &sx, &sy, &fx, &fy, &N) ;
    count = 0 ;
    while(N--){
      scanf("%d %d %d", &cx, &cy,&r) ;
      count += in_planet(sx, sy, fx, fy, cx, cy, r) ;
    }
    printf("%d\n",count) ;
  } 
}