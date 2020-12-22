#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std ;
int N, M ;
list <int> w ;

int
main () {
  int carrier = 0 ; 
  int num ;
  cin >> M ;

  while(scanf("%d", &num) != EOF){
    w.push_back(num) ;
  }
  w.sort() ;

  while(!w.empty()){
    if(w.size() == 1){
      carrier += 1 ;
      w.pop_back() ;
    }
    else if(w.front() + w.back() <= M){
      carrier += 1 ;
      w.pop_back() ;
      w.pop_front() ;
    }
    else if(w.front() > M/2){
      carrier += w.size() ;
      break ;
    }
    else{
      carrier += 1 ;
      w.pop_back() ;
    }
  }
  cout << carrier ;

}