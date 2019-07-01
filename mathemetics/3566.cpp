#include <iostream>
#include <algorithm>
using namespace std ;

int RH, RV, SH, SV , N  ;
int min_p ;
void comp_min(int p){
  if(min_p == 0){
    min_p = p ;
  }
  else min_p = min(p, min_p) ; 
}

void solution(int m[][5+1], int rh, int rv, int sh, int sv){
  for(int i = 1 ; i <= N ; i++){
    int hor = 1, ver = 1 ;
    if(RH / m[i][rh]){
      (RH % m[i][rh] == 0) ? hor = RH / m[i][rh] : hor = RH / m[i][rh] + 1 ; 
    }
    if(RV / m[i][rv]){
      (RV % m[i][rv] == 0) ? ver = RV / m[i][rv] : ver = RV / m[i][rv] + 1; 
    }
    if(SH / m[i][sh]){
      if(SH % m[i][sh] == 0){
        hor = max(hor, SH / m[i][sh]) ;
      }
      else{
        hor = max(hor,SH / m[i][sh] + 1) ; 
      }
    }
    if(SV / m[i][sv]){
      if(SV % m[i][sv] == 0){
        ver = max(ver, SV / m[i][sv]) ; 
      }
      else{
        ver = max(ver, SV / m[i][sv] + 1) ; 
      }
    }
    comp_min(hor*ver*m[i][5]) ;
  }
}
int main(){
  scanf("%d %d %d %d %d",&RH, &RV, &SH,&SV, &N) ;
  int monitor[N+1][5+1] ; 
  for(int i = 1; i <= N; i++){
    scanf("%d %d %d %d %d",&monitor[i][1], &monitor[i][2], &monitor[i][3], &monitor[i][4], &monitor[i][5]) ; 
  }
  solution(monitor, 1, 2, 3, 4) ; 
  solution(monitor, 2, 1, 4, 3) ; // 회전
  printf("%d\n",min_p) ;
}