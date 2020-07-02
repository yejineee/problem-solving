#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ; 

int main(){
  int N, final_result, num ; 
  vector<int> number ; 
  vector<long long> prev_result(21,0), next_result(21,0) ; 

  scanf("%d", &N) ;
  for(int i = 0 ; i < N ; i++){
    scanf("%d", &num) ;
    if(i == N-1){
      final_result = num ;
    }
    else{
      number.push_back(num) ; 
    }
  }

  prev_result[number[0]] = 1 ; 
  for(int i = 1; i < number.size() ; i++){
    int n = number[i] ; 
    for(int i = 0 ; i < prev_result.size() ; i++){
      long long num_of_value = prev_result[i] ; 
      if(num_of_value > 0){
        if( i + n >= 0 && i + n <= 20){
          next_result[i+n] += num_of_value ; 
        }
        if( i - n >= 0 && i - n <= 20){
          next_result[i-n] += num_of_value ; 
        }
      }
    }
    prev_result = next_result ; 
    fill(next_result.begin(), next_result.end(), 0) ; 
  }

  printf("%lld", prev_result[final_result]) ; 
  return 0 ; 
}