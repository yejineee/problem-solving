#include <iostream>       
#include <queue>          
#include <vector>         
#include <functional>    

using namespace std ;


class abs_sort
{
  bool reverse;
public:
  abs_sort() {}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if(abs(lhs) == abs(rhs)){
      return lhs > rhs ; 
    }
    return abs(lhs) > abs(rhs) ; 
  }
};

int main ()
{
  int N ;
  typedef priority_queue<int,vector<int>,abs_sort> pq_abs ;
  pq_abs abs_heap ; 

  scanf("%d", &N) ; 

  while(N--){
    int n ; 
    scanf("%d", &n) ; 
    if(n == 0){
      if(abs_heap.empty()){
        puts("0") ; 
      }
      else{
        printf("%d\n", abs_heap.top()) ;
        abs_heap.pop() ; 
      }
    }
    else{
      abs_heap.push(n) ; 
    }
  }



  return 0;
}


