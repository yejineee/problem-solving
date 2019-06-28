#include <iostream>
using namespace std ;

void swap(int *arr, int a, int b){
  int temp ; 
  temp = arr[a] ; 
  arr[a] = arr[b] ; 
  arr[b] = temp ; 
}
int sort_sum(int* arr, int n){
  int min_idx ; 
  int i, j ;
  int require = 0 , sum = 0 ; 

  for( i = 0 ; i < n-1 ; i++){
    min_idx = i ;
    for( j = i+1 ; j < n ; j++){
      if(arr[min_idx] > arr[j]){
        min_idx = j ; 
      }
    }

    require += arr[min_idx] ; 
    sum += require ; 
    swap(arr, i, min_idx) ;
  }
  require += arr[n-1] ; 
  sum += require ; 

  return sum ; 
}

int main(){
  int N ; 
  scanf("%d",&N) ; 
  int P[N] ; 
  for(int i = 0 ; i < N ; i++){
    scanf("%d",&P[i]) ; 
  }
  cout << sort_sum(P, N) << endl ; 
}