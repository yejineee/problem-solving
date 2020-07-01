#include <iostream>
#include <vector>
using namespace std ;

vector<int> port_to_port ;
vector<int> link ;

int lower_bound_idx(int port){
  int start = 0, end = link.size(), mid = (start+end) / 2 ; 

  while(start < end){
    mid = (start+end) / 2 ;
    if(link[mid] >= port){
      end = mid ; 
    }
    else{
      start = mid+1 ; 
    }
  }
  return end ; 
}
int main(){
  int n_port ;
  scanf("%d", &n_port) ;

  while(n_port--){
    int port ;
    scanf("%d", &port) ;
    port_to_port.push_back(port) ;
  }

  for(const auto& p : port_to_port){
    int i = lower_bound_idx(p) ;
    if(i == link.size()){
      link.push_back(p) ;
    }
    else{
      link[i] = p ;
    }
  }

  printf("%lu\n", link.size()) ;
  return 0 ;
}
