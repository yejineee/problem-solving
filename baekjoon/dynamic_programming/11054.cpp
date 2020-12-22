#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ; 

const int MAX_N = 1000 ; 
int N ; 
int n_increasing[MAX_N], n_decreasing[MAX_N] ;
vector<int> seq, num ;

void find_LIS(int store[MAX_N]){
  seq.push_back(num[0]) ;
  store[0] = 1 ; 
  for(int i = 1 ; i < N ; i++){
    if(num[i] < seq.back()){
      vector<int>::iterator low = lower_bound(seq.begin(), seq.end(), num[i]) ;
      seq[low-seq.begin()] = num[i] ; 
    }
    else if(num[i] > seq.back()){
      seq.push_back(num[i]) ; 
    }
    store[i] = seq.size() ; 
  }
  return ; 
}
int main(){
  int longest_len = 0 ;
  scanf("%d", &N) ; 
  for(int i = 0  ; i < N ; i++){
    int in ;
    scanf("%d", &in) ; 
    num.push_back(in) ; 
  }
  find_LIS(n_increasing) ; 
  seq.clear() ; 
  reverse(num.begin(), num.end()) ;
  find_LIS(n_decreasing) ; 
  reverse(n_decreasing, n_decreasing+N) ; 

  for(int i = 0 ; i < N ; i++){
    longest_len = max(longest_len, n_increasing[i] + n_decreasing[i] -1) ;
  }
  printf("%d", longest_len) ; 
  return 0 ;
}