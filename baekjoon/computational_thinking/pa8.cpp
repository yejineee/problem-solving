#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std ; 

const int MAX_N = 100000 ; 
double loc[MAX_N] ; 
double bound_r[MAX_N] ;
double radius[MAX_N] ; 
vector<int> prev_r ;

double get_max_r(double x1, double y1, double x2){
  return (pow(x1-x2,2)) / (4*y1) ; 

}

void find_radius(int idx){
  double cur_r = get_max_r(loc[prev_r.back()], radius[prev_r.back()], loc[idx]) ; 
  if(cur_r > bound_r[idx]){
    cur_r = bound_r[idx] ;
  }

  while(!prev_r.empty()){
    int last_r_idx = prev_r.back() ; 
    double last_r = radius[last_r_idx] ; 
    double test_r = get_max_r(loc[last_r_idx], last_r, loc[idx]) ; 
    cur_r = fmin(cur_r, test_r) ; 

    if(cur_r >= last_r){
      prev_r.pop_back() ; 
    } 
    else{
      prev_r.push_back(idx) ; 
      radius[idx] = cur_r ; 
      break ; 
    }
  }
  if(prev_r.empty()){
    radius[idx] = cur_r ; 
    prev_r.push_back(idx) ; 
  }
}

int main(){
  int N ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N ; i++){
    scanf("%lf %lf", &loc[i], &bound_r[i]) ;
  }
  radius[0] = bound_r[0] ;
  prev_r.push_back(0) ; 

  for(int i = 1 ; i < N ; i++){
    find_radius(i) ; 
  }

  for(int i = 0 ; i < N ; i++){
    printf("%.3lf\n",radius[i]) ;
  }



}