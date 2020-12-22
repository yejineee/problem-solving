#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std ; 
const int MAX_N = 50000 ; 
int card[MAX_N] ; 
int asc[MAX_N] ;
int dsc[MAX_N] ; 
int N ;

int find_max_num_card(){
  int idx_max_asc = 0 ;
  int max_total_dsc = 0 ;
  int max_local_dsc = 0 ; 
  int max_num_card = 0 ;

  for(int i = 0 ; i < N ; i++){
    for(int prev = 0 ; prev < i ; prev++){
      if(card[prev] < card[i]){
        if(asc[i] < asc[prev] + 1){
          asc[i] = asc[prev] + 1 ; 
        }
      }
      if(prev >= idx_max_asc){
        if(card[prev] > card[i]){
          if(dsc[i] < dsc[prev] + 1){
            dsc[i] = dsc[prev] + 1 ; 
          }
        }
        max_local_dsc = max(max_local_dsc, dsc[i]) ; 
      }
    }
    if(asc[i] > asc[idx_max_asc]){
      max_num_card = max(max_num_card, asc[idx_max_asc] + max_local_dsc) ; 
      idx_max_asc = i ; 
      dsc[i] = 0 ;
      max_local_dsc = 0 ;
    }
    max_total_dsc = max(max_total_dsc, max_local_dsc) ; 
    // printf("[%d] asc : %d | dsc : %d | max_asc : %d | max_local : %d | max_total : %d | max_num: %d\n", 
    //                   card[i], asc[i], dsc[i],card[idx_max_asc], max_local_dsc, max_total_dsc, max_num_card ) ; 
  }
  max_num_card = max(max_num_card, asc[idx_max_asc] + max_local_dsc) ;
  max_num_card = max(max_total_dsc + 1, max_num_card) ; 
  return max_num_card ; 
}


int main() {
  scanf("%d", &N) ;
  for(int i = 0 ; i < N ; i++){
    scanf("%d", &card[i]) ; 
  }
  fill(asc, asc+N, 1) ; 
  fill(dsc, dsc+N, 0) ; 
  int ret = find_max_num_card() ;
 // printf("result : %d\n", ret) ;
  printf("%d",ret) ; 

}
