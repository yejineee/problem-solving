#include <iostream>
#include <utility>
#include <algorithm>
using namespace std ; 

int max_s ;
int N ;
int stair[301] ; 
pair<int, int> table[301] ;


void 
dp (int n, int flag, int sum){
  int ret ;
  if(n < 1){
    max_s = max(max_s, sum) ;
    return ;
  }
  if(flag == 1){
    //table[n].first = stair[n] + sum ;
    ret = stair[n] + sum ;
    if(ret < table[n].first) return ;
    table[n].first = ret ; 
    dp(n-2, 2, table[n].first) ;
  }
  else if(flag == 2){
    //table[n].second = stair[n] + sum ;  
    ret = stair[n] + sum ;  
    if(ret < table[n].second) return ;
    table[n].second = ret ; 
    dp(n-1, 1, table[n].second ) ;
    dp(n-2, 2, table[n].second ) ;  
  }

}

int 
main () {
  scanf("%d", &N) ; 
  for(int i = 1 ; i <= N ; i++){
    scanf("%d",&stair[i]) ; 
  }

  dp(N-1, 1, stair[N]) ;
  dp(N-2, 2, stair[N]) ;
  printf("%d\n", max_s ) ; 
}