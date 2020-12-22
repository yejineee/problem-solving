#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std ;

const int MAX_N = 500 ; 
vector<string> splitted_path[MAX_N] ; 
int N ;


void print_path(int idx, int offset){
  int n_blank = offset ; 
  string s ; 
  for(int i =  offset ; i < splitted_path[idx].size() ; i++){
    s = splitted_path[idx][i] ;
    for(int i = 0 ; i < n_blank ; i++){ 
      s = " " + s; 
    }
    printf("%s\n", s.c_str()) ;
    n_blank += 1 ;
  }
}
int comp_path(int idx){
  int match = 0 ;
  int n_comp = min(splitted_path[idx].size(), splitted_path[idx-1].size()) ; 
  for(int i = 0 ; i < n_comp ; i++){
    if(splitted_path[idx][i] == splitted_path[idx-1][i]){
      match += 1 ;
    }
    else break ; 
  }
  return match ;
}
void disk_tree(){
  print_path(0, 0) ;
  for(int i = 1 ; i < N ; i++){
    int start = comp_path(i) ; 
    print_path(i, start) ;
  }
}
bool comp(vector<string> a, vector<string> b){
  int n_comp = min(a.size(), b.size()) ;
  int i ; 
  for(i = 0 ; i < n_comp ; i++){
    if(a[i] == b[i]) continue ; 
    else return a[i] < b[i] ;
  }
  return a.size() < b.size(); 
}
int main(){
  int idx = 0 ; 
  scanf("%d",&N) ; 

  for(int i = 0 ; i < N ; i++){
    char path[81] ; 
    scanf("%s", path) ; 
    char *ptr = strtok(path, "\\") ; 
    while(ptr != NULL){
      string s (ptr) ; 
      splitted_path[idx].push_back(s) ; 
      ptr = strtok(NULL, "\\") ;
    }
    idx += 1 ;
  }
  sort(splitted_path, splitted_path+N, comp) ;
  disk_tree() ; 
  return 0 ;
}