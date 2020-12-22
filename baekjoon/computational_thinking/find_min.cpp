#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std ;
int main(int argc, char** argv){
  double n ; 
  double min_n = 2000000000 ; 
  for(int i = 0 ; i < atoi(argv[1]) ; i++){
    scanf("%lf", &n);
    min_n = min(min_n, n) ; 
  }
  printf(">> ") ; 
  cout << min_n << endl ; 
}