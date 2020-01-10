#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ; 

int N ; 
vector<int> num ; 

void search(int n){
  int lower = 0 ;
  int upper = N-1 ; 
  
  while(lower <= upper){
    int mid = (lower+upper) / 2 ; 
    if(num[mid] == n){
      puts("1") ; 
      return ; 
    }
    else if(num[mid] > n){
      upper = mid-1 ; 
    }
    else{
      lower = mid+1 ; 
    }
  }
  puts("0") ;
  return ; 
}



int main(){
  int M ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N ; i++){
    int n ; 
    scanf("%d", &n) ; 
    num.push_back(n) ; 
  }
  sort(num.begin(), num.end()) ; 
  scanf("%d", &M) ; 
  for(int i = 0 ; i < M ; i++){
    int n ; 
    scanf("%d", &n) ; 
    search(n) ; 
  }

}