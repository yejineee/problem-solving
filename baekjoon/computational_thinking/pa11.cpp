#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std ; 
const int MAX_N = 100000 ; 
int N, M, D ; 
int max_count_s = 0 ;
int due[MAX_N+1] ; 

bool check_valid(int bulldozer){
  int Q, R ; 
  int due_copy[N+1] ; 
  memcpy(due_copy, due, sizeof(int) * (N+1)) ; 

  for(int i = 1 ; i <= N-D ; i++){
    Q = due_copy[i] / bulldozer ; 
    R = due_copy[i] % bulldozer ; 
    if(Q > D+1){
      return false ; 
    }
    if(Q == D+1 && R != 0){
      return false ; 
    }
    if(due_copy[i] > bulldozer){
      due_copy[i+1] += due_copy[i]-bulldozer ; 
    }
  }
  return true ; 
}

int find_min_bulldozer(){
  int lower = 1 ; 
  int upper = max_count_s ; 
  int mid ; 

  while(lower <= upper){
    mid = (lower + upper) / 2 ;
    if(check_valid(mid)){
      upper = mid-1 ; 
    }
    else{
      lower = mid+1 ; 
    }
  }
  return lower ; 
}

int main(){

  scanf("%d %d %d", &N, &D, &M) ; 
  for(int i = 1 ; i <= M ; i++){
    int s ; 
    scanf("%d", &s) ; 
    due[s] += 1 ; 
    max_count_s = max(max_count_s, due[s]) ;
  }

  printf("%d", find_min_bulldozer()) ; 
}