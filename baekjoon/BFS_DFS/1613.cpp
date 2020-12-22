#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ; 
const int MAX_EVENT = 400 ;
vector<int> relation[MAX_EVENT+1] ; 
bool visit [MAX_EVENT+1] ; 
int n_event ; 
int A, B;
bool if_find ; 

void find_event(int start, int event){
  visit[start] = true ; 
  for(int i = 0 ; i < relation[start].size() ; i++){
    int there = relation[start][i] ; 
    if(there == event){
      if_find = true ; 
      return ; 
    }
    if(!visit[there]){
      find_event(there, event) ; 
    }
  }
}

int main(){
  int n_relation, s ; 
  scanf("%d %d", &n_event, &n_relation) ; 
  while(n_relation--){
    int pre, post ; 
    scanf("%d %d", &pre, &post) ; 
    relation[pre].push_back(post) ; 
  }
  scanf("%d", &s) ; 
  while(s--){
    scanf("%d %d", &A, &B) ;
    fill(visit+1, visit+n_event+1, 0) ; 
    if_find = false ; 
    find_event(A, B) ; 
    if(if_find){
      puts("-1") ;
    }
    else{
      fill(visit+1, visit+n_event+1, 0) ; 
      if_find = false ; 
      find_event(B, A) ; 
      if(if_find){
        puts("1") ; 
      }
      else{
        puts("0") ; 
      }
    }
  }
  return 0 ; 
}