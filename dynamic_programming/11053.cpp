#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ; 

const int MAX_N = 1000 ; 
int N ; 
int num[MAX_N] ; 
vector<int> seq ;

int find_LIS(){
  seq.push_back(num[0]) ;
  for(int i = 1 ; i < N ; i++){
    if(num[i] < seq.back()){
      vector<int>::iterator low = lower_bound(seq.begin(), seq.end(), num[i]) ;
      seq[low-seq.begin()] = num[i] ; 
    }
    else if(num[i] > seq.back()){
      seq.push_back(num[i]) ; 
    }
  }
  return seq.size() ; 
}
int main(){
  scanf("%d", &N) ; 
  for(int i = 0  ; i < N ; i++){
    scanf("%d", &num[i]) ; 
  }
  printf("%d", find_LIS()) ; 
  return 0 ;
}