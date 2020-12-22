#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std ;
const int MAX_BLOCK = 5 ;
int max_n, min_n, N, n_block;
vector<string> block[MAX_BLOCK+1] ;
int n_unit = 0 ; 

void init(string &used, string &square){
  used.assign(n_block+1, '0') ; 
  square.assign(N*N, '0') ; 
}
void print_matrix(string square){
  int m[N][N] ;
  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      m[r][c] = square[r*N +c]-'0' ; 
      printf("%d ", m[r][c]) ; 
    }
    printf("\n") ; 
  }
}
bool match_block(string &square, int idx_b, int start_r, int start_c){
  int h = block[idx_b].size() ; 
  int w = block[idx_b].front().length() ; 
  vector<string>::iterator it = block[idx_b].begin() ; 
  int not_0_idx = block[idx_b].front().find_first_not_of("0") ; 
  string r_block ;

  if(start_r + h > N){
    return false ;
  }
  if(start_c - not_0_idx + w > N){
    return false ; 
  }
  for(int r = start_r ; r < start_r+h ; r++, it++){
    if(r >= N) return false ;
    r_block = *it ; 

    int c = start_c - not_0_idx ; 
    if(c >= N) return false ;
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

  if(is_valid(used, square)){
    print_matrix(square) ; 
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

bool impossible(int n){
  double len = sqrt(n) ; 
  if(len - (int)len != 0){
    return true ; 
  }
  return false ;
}

int main() {
  int h, w, in; 
  string s ;
  scanf("%d", &n_block) ;
  for(int i = 1; i <= n_block ; i++){
    scanf("%d %d", &h, &w) ;
    for(int r = 0 ; r < h ; r++){
      s = "" ; 
      for(int c = 0 ; c < w ; c++){
        scanf("%d", &in) ;
        if(in != 0){
          in = i ;
          n_unit += 1 ; 
        }
        stringstream ss ; 
        ss << in ; 
        s += ss.str() ; 
      }
      block[i].push_back(s) ;
    }
  }
  if(impossible(n_unit)){
    puts("No solution possible") ; 
  }
  else{
    N = sqrt(n_unit) ; 
    string used, square ; 
    init(used, square) ;
    if(make_square(used, square)){
      return 0 ; 
    }else{
      puts("No solution possible") ; 
    }
  }
  return 0 ; 
}