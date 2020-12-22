#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std ; 
const int MAX_N = 50000 ; 
vector<int> sequence ; 
int card[MAX_N] ; 
int asc[MAX_N] ;
int dsc[MAX_N] ; 
int N ;

int find_location(int n){
  int lower = 0 ; 
  int upper = sequence.size() -1 ;

  while(lower <= upper){
    int mid = (lower + upper) / 2 ; 
    if(sequence[mid] == n){
      return mid ; 
    }
    else if(sequence[mid] < n){
      lower = mid + 1 ; 
    }
    else{
      upper = mid - 1 ; 
    }
  }
  return lower ; 
}

void find_num_ascending(){
  for(int i = 0 ; i < N ; i++){
    if(sequence.empty()){
      sequence.push_back(card[i]) ; 
    }
    else if(sequence.back() < card[i]){
      sequence.push_back(card[i]) ; 
    }
    else{
      int loc = find_location(card[i]) ;
      sequence[loc] = card[i] ; 
    }
    asc[i] = sequence.size() ;
  }
}
void find_num_descending(){
  for(int i = N-1; i >= 0 ; i--){
    if(sequence.empty()){
      sequence.push_back(card[i]) ; 
    }
    else if(sequence.back() < card[i]){
      sequence.push_back(card[i]) ; 
    }
    else{
      int loc = find_location(card[i]) ;
      sequence[loc] = card[i] ; 
    }
    dsc[i] = sequence.size() ;
  }
}
int find_max_num(){
  int max_card = 0 ; 
  for(int i = 0 ; i < N ; i++){
    if(max_card < asc[i] + dsc[i] -1){
      max_card = asc[i] + dsc[i] -1 ; 
    }
  }
  return max_card ; 
}
int main() {
  scanf("%d", &N) ;
  for(int i = 0 ; i < N ; i++){
    scanf("%d", &card[i]) ; 
  }

  find_num_ascending() ;
  sequence.clear() ;
  find_num_descending() ;
  int ret = find_max_num() ; 
  printf("%d\n",ret) ; 
  printf("\nnum : ") ; 
  for(int i = 0 ; i < N ; i++){
    printf("%3d|", card[i])  ;
  }
  printf("\nasc : ") ; 
  for(int i = 0 ; i < N ; i++){
    printf("%3d|", asc[i])  ;
  }
  printf("\ndsc : ") ; 
  for(int i = 0 ; i < N ; i++){
    printf("%3d|", dsc[i])  ;
  }
  printf("\nsum : ") ; 
  for(int i = 0 ; i < N ; i++){
    printf("%3d|", asc[i] + dsc[i] -1)  ;
  }
  printf("result : %d\n",ret ) ;
}
