#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std ;
const int MAX_BLOCK = 5 ;
int max_n = 8, min_n = 0, N, n_block;
vector<string> block[MAX_BLOCK+1] ;

void init(string &used, string &square){
  used.assign(n_block+1, '0') ; 
  square.assign(N*N, '0') ; 
}


bool match_block(string &square, int idx_b, int start_r, int start_c){
  int h = block[idx_b].size() ; 
  int w = block[idx_b].front().length() ; 
  vector<string>::iterator it = block[idx_b].begin() ; 
  int not_0_idx = block[idx_b].front().find_first_not_of("0") ; 
  string r_block ;
  //printf("block :%d, start_r : %d, h : %d\n", idx_b, start_r, h) ; 
 
  if(start_r + h > N){
    return false ;
  }
  if(start_c - not_0_idx + w > N){
    return false ; 
  }
  for(int r = start_r ; r < start_r+h ; r++, it++){
    r_block = *it ; 
    //printf("r_block  : %s\n", r_block.c_str()) ; 
    int c = start_c - not_0_idx ; 
    for(int x = 0 ; x < w ; x++){
      if(square[r*N +c] != '0' && r_block[x] != '0'){
        return false ; 
      }
      if(square[r*N +c] != '0' && r_block[x] == '0'){
        c += 1 ; 
        continue ;
      }
      square[r*N +c] = r_block[x] ; 
      c += 1 ;
    }
  }

  return true ;
}
bool is_valid(string used, string square){
  if(used.find_last_of("0") != 0){
    return false ; 
  }
  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      if(square[r*N + c] == '0'){
        return false ;
      }
    }
  }
  return true ; 
}
bool make_square(string &used, string &square){
  /*
  puts("-----------------------") ;
    for(int r = 0 ; r < N ; r++){
      for(int c = 0 ; c < N ; c++){
        printf("%c ",square[r*N + c]) ; 
      }
      printf("\n") ; 
    }
    */
  if(is_valid(used, square)){
    for(int r = 0 ; r < N ; r++){
      for(int c = 0 ; c < N ; c++){
        if(r == N-1 && c == N-1) printf("%c", square[r*N + c]) ; 
        else if(c == N-1) printf("%c\n", square[r*N + c]) ;
        else printf("%c ",square[r*N + c]) ; 
      }
    }
    return true ;
  }

  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      if(square[r*N + c] == '0'){
        for(int b = 1 ; b <= n_block ; b++){
          if(used[b] == '1') continue ; 
          string s_next = square ; 
          string u_next = used ; 
          if(match_block(s_next, b, r, c)){
            u_next[b] = '1' ; 
            if(make_square(u_next, s_next)){
              return true ;
            } 
          }
        }
      }
    }
  }

  return false ; 
}
bool decreasing (int i, int j) { 
  return i > j ; 
}

int main() {
  int h, w, in; 
  string s ;
  scanf("%d", &n_block) ;
  for(int i = 1; i <= n_block ; i++){
    scanf("%d %d", &h, &w) ;
    min_n = max(min_n, h) ;
    min_n = max(min_n, w) ;
    for(int r = 0 ; r < h ; r++){
      s = "" ; 
      for(int c = 0 ; c < w ; c++){
        scanf("%d", &in) ;
        if(in != 0) in = i ;
        stringstream ss ; 
        ss << in ; 
        s += ss.str() ; 
      }
      block[i].push_back(s) ;
    }
  }


  for(N = min_n ; N <= max_n ; N++){
    string used ;
    string square ; 
    init(used, square) ;
    if(make_square(used, square)){
      return 0 ; 
    }
  }
  puts("No solution possible") ; 
  return 0 ; 
}