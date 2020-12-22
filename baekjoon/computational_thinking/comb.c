//
//  main.c
//  combination
//
//  Created by 양예진 on 02/04/2019.
//  Copyright © 2019 양예진. All rights reserved.
//

#include <stdio.h>
#define MAXSIZE 100
#define FALSE 0
int RCcombination(int n, int k){
    if( n == k || k == 0)
        return 1;
    if( k >= 1 && k <= n-1)
        return RCcombination(n-1, k-1) + RCcombination(n-1, k);
    return -1;
}

long long DPcombination(int n, int k){
    long long com, c1, c2;
    long long DP[MAXSIZE][MAXSIZE] = {FALSE,};
    
    if( k == 0 || n == k )
        com = 1;
    if( k >= 1 && k <= n-1 ){
        if(DP[n-1][k-1] == FALSE) c1 = DPcombination(n-1,k-1);
        else c1 = DP[n-1][k-1];
        if(DP[n-1][k] == FALSE) c2 = DPcombination(n-1,k);
        else c2 = DP[n-1][k];
        com = c1 + c2;
    }
    DP[n][k] = com;
    return DP[n][k];
}
int main(int argc, const char * argv[]) {
    int a, b;

    while(1){
        printf("a, b : ");
        scanf("%d %d",&a, &b);
        printf("DP Combination(%d,%d) = %lld\n", a, b, DPcombination(a, b));
        printf("Recurr Combination(%d,%d) = %d\n", a, b, RCcombination(a, b));
    }
    if(i+1 <= n_rod && !current[i+1].empty() && current[i].back() < current[i+1].back()){
    //printf("-> %d\n", i+1) ;
      for(int j = 1 ; j <= n_rod ; j++){
        next[j] = current[j] ;
      }
      next[i+1].push_back(next[i].back()) ;
      next[i].pop_back() ;
      if(!is_visit(prev, next))
        min_move = min(min_move, hanoi(current, next, move+1)) ;
    }
    if(i+1 <= n_rod){
        for(int j = 1 ; j <= n_rod ; j++){
            next[j] = current[j] ;
        }
        if(next[i+1].empty()){
            next[i+1].push_back(next[i].back()) ;
            next[i].pop_back() ;
            if(!is_visit(prev, next)) 
                min_move = min(min_move, hanoi(current, next, move+1)) ;
            
        }
        else if(!next[i+1].empty() && next[i].back() < next[i+1].back()){
            next[i+1].push_back(next[i].back()) ;
            next[i].pop_back() ;
            if(!is_visit(prev, next))
                min_move = min(min_move, hanoi(current, next, move+1)) ;
        }
    }
    return 0;
}
