#include <iostream>
#include <string>
#include <unordered_set>
#include <ctype.h>
using namespace std ;
const int MAX_SIZE = 5 ;
const int FALSE = 0 ;
const int TRUE = 1 ;
string board[MAX_SIZE+1][MAX_SIZE+1] ;
unordered_set<string> numSet ;
unordered_set<string>::iterator it ;

int check_valid(string s){
  if(numSet.find(s) == numSet.end()){
    return TRUE ;
  }
  return FALSE ;
}

void 
go (int y, int x, string s){
  
  if(s.length() == 6){
    if(check_valid(s)){
      numSet.insert(s) ;
    }
    return ;
  }
  if( x > 1 ) // left
  {
    string str = s ;
    str += board[y][x-1] ;
    go(y, x-1, str) ;
  }
  if( x < MAX_SIZE ) // right
  {
    string str = s ;
    str += board[y][x+1] ;
    go(y, x+1, str) ;
  }
  if( y > 1 ) // down
  {
    string str = s ;
    str += board[y-1][x] ;
    go(y-1, x, str) ;
  }
  if( y < MAX_SIZE ) // up
  {
    string str = s ;
    str += board[y+1][x] ;
    go(y+1, x, str) ;
  }
  return ;
}

int 
main () {
  int in ;
  for(int i = 1 ; i <= MAX_SIZE ; i++){
    for(int j = 1 ; j <= MAX_SIZE ; j++){
      scanf("%d", &in) ;
      board[i][j] = to_string(in) ;
    }
  }
  string start ;
  for(int i = 1 ; i <= MAX_SIZE ; i++){
    for(int j = 1 ; j <= MAX_SIZE ; j++){
      start = board[i][j] ;
      go(i, j, start) ;
    }
  }
  cout << numSet.size() << '\n' ;



}