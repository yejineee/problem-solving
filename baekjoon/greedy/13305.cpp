#include <iostream>

using namespace std;

int main(){
  int city ; 
  scanf("%d",&city);   

  long long node[city+1] ;
  long long edge[city] ;

  for(int i = 1; i < city ; i++){
    scanf("%lld",&edge[i]);
  }
  for(int i = 1; i < city+1 ; i++){
    scanf("%lld",&node[i]);
  }
  long long price = 0; 
  int min = node[1] ; 
  for(int i = 1 ; i < city ; i++){
    if(node[i] < min){
      min = node[i] ; 
    }
    price += min*edge[i] ; 
  }

  cout << price << endl ; 

}