#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

const int MAX_N = 100000 ; 
double loc[MAX_N] ; 
double bound_r[MAX_N] ;
double radius[MAX_N] ; 
double max_x, max_r ;
int max_idx ;  

double get_max_r(double x1, double y1, double x2){
  return (pow(x1-x2,2)) / (4*y1) ; 

}

void find_radius(int idx){
  printf("-------- %.0lf-------\n", loc[idx]) ; 
  printf("%.0lf | max_x : %.3lf, max_r : %.3lf\n", loc[max_idx], max_x, max_r) ; 
  double from_max_r = get_max_r(max_x, max_r, loc[idx]) ;
  double from_prev_r = get_max_r(loc[idx-1], radius[idx-1], loc[idx]) ; 

  double ret = fmin(bound_r[idx], from_max_r) ; 
  ret = fmin(ret, from_prev_r) ; 

  radius[idx] = ret ; 
  if(radius[idx-1] <= radius[idx]){
    max_idx = idx ; 
    max_x = loc[idx] ; 
    max_r = radius[idx] ; 
  }

  printf("bound [ %.3lf ] vs from_max_r [ %.3lf ] vs from_prev_r[ %.3lf ] --> raidus[ %.3lf ]\n",bound_r[idx],from_max_r, from_prev_r, radius[idx]) ;

}

int main(){
  int N ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N ; i++){
    scanf("%lf %lf", &loc[i], &bound_r[i]) ;
  }
  radius[0] = bound_r[0] ;
  max_idx = 0 ; 
  max_x = loc[0] ; 
  max_r = radius[0] ; 

  for(int i = 1 ; i < N ; i++){
    find_radius(i) ; 
  }

  for(int i = 0 ; i < N ; i++){
    printf("%.0lf -  %.3lf\n", loc[i], radius[i]) ;
    // printf("%.3lf\n",radius[i]) ;
  }
  
  for(int i = 1 ; i < N ; i++){
    printf("----------------%.0lf ( ~ %.3lf)-------------\n", loc[i], bound_r[i]) ; 
    for(int j = i-1 ; j >= 0 ; j--){
      printf("%.0lf ) max : %.3lf\n", loc[j], get_max_r(loc[j], radius[j], loc[i])) ; 
    }
  }
}