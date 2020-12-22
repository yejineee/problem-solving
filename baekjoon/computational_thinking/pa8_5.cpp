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
vector<pair<double, double> > loc_boundR ; 
double radius[MAX_N] ; 
double max_r ; 
vector<pair<double, double> > hill ; 
vector<pair<double, double> > check_hill ; 


double get_max_r(double x1, double y1, double x2){
  return (pow(x1-x2,2)) / (4*y1) ; 

}

void find_radius(int idx){
  //printf("\n----------------%.0lf ( ~ %.3lf)-------------\n", loc_boundR[idx].first, loc_boundR[idx].second) ; 
  double ret = loc_boundR[idx].second ; 
  //printf("<hill>\n") ; 
  for(vector<pair<double, double> >::iterator it = hill.begin() ; it != hill.end() ; it++){
    double l = get_max_r((*it).first, (*it).second, loc_boundR[idx].first) ; 
    //printf("[ %.0lf (r : %.3lf )] max : %.3lf\n",(*it).first, (*it).second, l ) ; 
    ret = fmin(ret, l) ; 
  }
  //printf("\n<check_hill>\n") ;
  for(vector<pair<double, double> >::iterator it = check_hill.begin() ; it != check_hill.end() ; it++){
    double l = get_max_r((*it).first, (*it).second, loc_boundR[idx].first) ; 
    //printf("[ %.0lf (r : %.3lf )] max : %.3lf\n",(*it).first, (*it).second, l ) ; 

    ret = fmin(ret, l) ; 
  }
  radius[idx] = ret ; 
  if(radius[idx-1] <= radius[idx]){
    //printf("-*-\n") ;  

    if(max_r <= radius[idx]){
      //printf("** max_hill = %.0lf\n", loc_boundR[idx].first) ; 
      max_r = radius[idx] ; 
      hill.clear() ;

    }
    else{
      for(int i = hill.size()-1 ; i > 0; i--){
        double last_r = hill[i].second ; 
        if(last_r <= radius[idx]){
          //printf("pop-hill : %.3lf\n", last_r) ;
          hill.pop_back() ; 

        }
        else break ;
      }
    }
    for(int i = check_hill.size()-1 ; i >= 0; i--){
      double last_r = check_hill[i].second ; 
      if(last_r <= radius[idx]){
        //printf("pop-check_hill : %.3lf\n", last_r) ;
        check_hill.pop_back() ; 

      }
      else break ;
    }

    hill.push_back(make_pair(loc_boundR[idx].first, radius[idx])) ; 
  }
  else{
    //if(hill.back().first + hill.back().second < loc_boundR[idx].first + radius[idx])
      check_hill.push_back(make_pair(loc_boundR[idx].first, radius[idx])) ; 
  }
  //printf("\n--> radius[ %.3lf ]\n", radius[idx]) ;

}

int main(){
  int N ; 
  scanf("%d", &N) ; 
  for(int i = 0 ; i < N ; i++){
    double x, r ;
    scanf("%lf %lf", &x, &r) ;
    loc_boundR.push_back(make_pair(x,r)) ; 
  }

  radius[0] = loc_boundR[0].second ;
  max_r = radius[0] ; 
  hill.push_back(make_pair(loc_boundR[0].first, radius[0] )) ; 
  //printf("----------------%.0lf ( ~ %.3lf)-------------\n", loc_boundR[0].first, loc_boundR[0].second) ; 
  //printf("--> radius[ %.3lf ]\n", radius[0]) ;

  for(int i = 1 ; i < N ; i++){
    find_radius(i) ; 
  }

  for(int i = 0 ; i < N ; i++){
    printf("%.3lf\n", radius[i]) ;
  }
  

}