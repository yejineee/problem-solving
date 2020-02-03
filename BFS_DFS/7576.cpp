#include <iostream>
#include <utility>
#include <list>
#include <unistd.h>
using namespace std ; 

const int MAX_LEN = 1000 ; 
int box[MAX_LEN+1][MAX_LEN+1] ; 
int row, col ; 
list<pair<int, int> > ripen, new_ripen ; 
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}} ; 

bool check_all_ripen(){
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      if(box[r][c] == 0){
        return false ; 
      }
    }
  }
  return true ; 
}

int find_min_days(){
  int days = 0 ;
  while(check_all_ripen() == false){
    days += 1 ; 
    if(days >= col*row) return -1 ; 
    for(list<pair<int, int> >::iterator it = ripen.begin() ; it != ripen.end() ; it++){
      int r = (*it).first ;
      int c = (*it).second ; 
      for(int i = 0 ; i < 4 ; i++){
        int next_r = r+dir[i][0] ; 
        int next_c = c+dir[i][1] ; 
        if( 1 <= next_r && next_r <= row && 1 <= next_c && next_c <= col){
          if(box[next_r][next_c] == 0){
            box[next_r][next_c] = 1 ; 
            new_ripen.push_back(make_pair(next_r, next_c)) ; 
          }
        }
      }
    }
    ripen.swap(new_ripen) ; 
    new_ripen.clear() ; 
  }
  return days ; 
}

int main(){
  scanf("%d %d", &col, &row) ; 
  for(int r = 1 ; r <= row ; r++){
    for(int c = 1 ; c <= col ; c++){
      int status ; 
      scanf("%d" , &status) ; 
      if(status == 1){
        ripen.push_back(make_pair(r,c)) ; 
      }
      box[r][c] = status ; 
    }
  }
  printf("%d", find_min_days()) ; 
}