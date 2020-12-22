#include <iostream>
#include <set>
#include <string>
using namespace std ; 
int main(){
  int N, M ; 
  set<string> not_heard, not_heard_seen ; 
  scanf("%d %d", &N , &M) ; 
  for(int i = 0 ; i < N ; i++){
    string s ; 
    cin >> s ; 
    not_heard.insert(s) ; 
  }
  for(int i = 0 ; i < M ; i++){
    string s ;
    cin >> s ; 
    if(not_heard.find(s) != not_heard.end()){
      not_heard_seen.insert(s) ; 
    }
  }
  printf("%lu\n", not_heard_seen.size()) ; 
  for(set<string>::iterator it = not_heard_seen.begin() ; it != not_heard_seen.end() ; it++){
    cout << *it << endl ; 
  } 
}