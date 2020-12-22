#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std ;
const int MAX_BLOCK = 5 ;
int N, n_block;
int block[MAX_BLOCK+1][4][4] ;
int height[MAX_BLOCK+1] ; 
int width[MAX_BLOCK+1] ; 
int total_unit = 0 ;
int first_nonzero[MAX_BLOCK+1] ; 



bool match_block(int square[8][8], int idx_b, int start_r, int start_c){
  int h = height[idx_b] ;
  int w = width[idx_b] ;
  int i_nonzero = first_nonzero[idx_b]; 
 
  if(start_r + h > N){
    return false ;
  }
  if(start_c - i_nonzero + w > N){
    return false ; 
  }
  int br = 0;
  for(int r = start_r; r < start_r+h && br < h; r++, br++){
    int c = start_c - i_nonzero ; 
    for(int bc = 0 ; bc < w ; bc++){
      if(square[r][c] != 0 && block[idx_b][br][bc] != 0){
        return false ; 
      }
      if(square[r][c] != 0 && block[idx_b][br][bc] == 0){
        c += 1 ; 
        continue ;
      }
      square[r][c] = block[idx_b][br][bc] ; 
      c += 1 ;
    }
  }

  return true ;
}
bool is_valid(int used[MAX_BLOCK+1], int square[8][8]){
  for(int i = 1 ; i <= n_block ; i++){
    if(used[i] == 0) return false ; 
  }
  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      if(square[r][c] == 0){
        return false ;
      }
    }
  }
  return true ; 
}
void copy_data(int dst_used[MAX_BLOCK+1], int dst_square[8][8], int src_used[MAX_BLOCK+1], int src_square[8][8]){
  for(int i = 1 ; i <= n_block ; i++){
    dst_used[i] = src_used[i] ; 
  }
  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      dst_square[r][c] = src_square[r][c] ; 
    }
  }
}
bool make_square(int used[MAX_BLOCK+1], int square[8][8]){

  if(is_valid(used, square)){
    for(int r = 0 ; r < N ; r++){
      for(int c = 0 ; c < N ; c++){
        printf("%d ", square[r][c]) ; 
      }
      printf("\n") ; 
    }
    return true ;
  }

  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      if(square[r][c] == 0){
        for(int b = 1 ; b <= n_block ; b++){
          if(used[b] == 1) continue ; 
          int u_next[MAX_BLOCK+1] ; 
          int s_next[8][8] ; 
          copy_data(u_next, s_next, used, square) ; 
          if(match_block(s_next, b, r, c)){
            u_next[b] = 1 ; 
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
void init(int used_arr[MAX_BLOCK+1], int matrix[8][8]){
  for(int i = 1 ; i <= n_block ; i++){
    used_arr[i] = 0 ;
  }
  for(int r = 0 ; r < N ; r++){
    for(int c = 0 ; c < N ; c++){
      matrix[r][c] = 0 ;
    }
  }
}
int main() {
  int h, w, in; 
  string s ;
  scanf("%d", &n_block) ;

  for(int i = 1; i <= n_block ; i++){
    scanf("%d %d", &h, &w) ;
    height[i] = h ;
    width[i] = w ;
    for(int r = 0 ; r < h ; r++){
      for(int c = 0 ; c < w ; c++){
        scanf("%d", &in) ;
        if(in != 0){
          block[i][r][c] =  i ;
          total_unit += 1 ; 
          if(first_nonzero[i] == 0) first_nonzero[i] = c ; 
        }
      }
    }
  }
  if(impossible(total_unit)){
    puts("No solution possible") ; 
  }
  else{
    N = sqrt(total_unit) ; 
    int used[MAX_BLOCK+1] ; 
    int square[8][8] ; 
    init( used, square) ; 
    if(make_square(used, square)){
      return 0 ; 
    }else{
      puts("No solution possible") ; 
    }
  }
  return 0 ; 
}