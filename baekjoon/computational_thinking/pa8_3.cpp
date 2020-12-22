#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <utility>
#include <stdlib.h>
#include <vector>
using namespace std ; 

const int MAX_N = 100000 ; 
const int INF = 2000000000 ; 
double loc_boundR[MAX_N][2] ; 
double radius[MAX_N] ; 
double max_r ; 
vector<pair<double, double> > hill ; 
vector<pair<double, double> > check_hill ; 


double get_max_r(double x1, double y1, double x2){
  return (pow(x1-x2,2)) / (4*y1) ; 

}

void find_radius(int idx){
  printf("\n----------------%.0lf ( ~ %.3lf)-------------\n", loc_boundR[idx][0], loc_boundR[idx][1]) ; 
  double ret = loc_boundR[idx][1] ; 
  printf("<hill>\n") ; 
  for(vector<pair<double, double> >::iterator it = hill.begin() ; it != hill.end() ; it++){
    double l = get_max_r((*it).first, (*it).second, loc_boundR[idx][0]) ; 
    printf("[ %.0lf (r : %.3lf )] max : %.3lf\n",(*it).first, (*it).second, l ) ; 
    ret = fmin(ret, l) ; 
  }
  printf("\n<check_hill>\n") ;
  for(vector<pair<double, double> >::iterator it = check_hill.begin() ; it != check_hill.end() ; it++){
    double l = get_max_r((*it).first, (*it).second, loc_boundR[idx][0]) ; 
    printf("[ %.0lf (r : %.3lf )] max : %.3lf\n",(*it).first, (*it).second, l ) ; 

    ret = fmin(ret, l) ; 
  }
  radius[idx] = ret ; 
  if(radius[idx-1] <= radius[idx]){
    if(max_r <= radius[idx]){
      printf("** max_hill = %.0lf\n", loc_boundR[idx][0]) ; 
      max_r = radius[idx] ; 
      hill.clear() ; 
    }
    else{
      for(int i = hill.size()-1 ; i > 0; i--){
        double last_r = hill[i].second ; 
        if(last_r <= radius[idx]){
          hill.pop_back() ; 
        }
        else break ;
      }
    }
    hill.push_back(make_pair(loc_boundR[idx][0], radius[idx])) ; 
    check_hill.clear() ;
  }
  else{
    check_hill.push_back(make_pair(loc_boundR[idx][0], radius[idx])) ; 
  }
  printf("\n--> radius[ %.3lf ]\n", radius[idx]) ;

}

int main(){
  int N ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N ; i++){
    scanf("%lf %lf", &loc_boundR[i][0], &loc_boundR[i][1]) ;
  }

  radius[0] = loc_boundR[0][1] ;
  max_r = radius[0] ; 
  hill.push_back(make_pair(loc_boundR[0][0], radius[0] )) ; 
  printf("----------------%.0lf ( ~ %.3lf)-------------\n", loc_boundR[0][0], loc_boundR[0][1]) ; 
  printf("--> radius[ %.3lf ]\n", radius[0]) ;

  for(int i = 1 ; i < N ; i++){
    find_radius(i) ; 
  }

  for(int i = 0 ; i < N ; i++){
    printf("%.3lf\n",radius[i]) ;
  }
  
  for(int i = 1 ; i < N ; i++){
    printf("----------------%.0lf ( ~ %.3lf)-------------\n", loc_boundR[i][0], loc_boundR[i][1]) ; 
    for(int j = i-1 ; j >= 0 ; j--){
      printf("%.0lf ) max : %.3lf\n", loc_boundR[j][0], get_max_r(loc_boundR[j][0], radius[j], loc_boundR[i][0])) ; 
    }
    printf("radius ; %.3lf\n",radius[i]) ;
  }
}