#include <iostream>
#include <algorithm>
#include <string.h>
#include <unistd.h>
using namespace std ;

const int MAX_N = 100 ; 
int N ; 
int height[MAX_N][MAX_N] ; 
bool visit[MAX_N][MAX_N] ; 
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}} ; 

void init_visit(){
    for(int r = 0 ; r < N ; r++){
        memset(visit+r, 0, N); 
    }
}

void check_safe_area(int r, int c, int h){
    visit[r][c] = true ; 

    for(int i = 0 ; i < 4 ; i++){
        int next_r = r + dir[i][0] ; 
        int next_c = c + dir[i][1] ; 
        if(next_r >= 0 && next_r < N && next_c >= 0 && next_c < N){
            if( height[next_r][next_c] > h && !visit[next_r][next_c] ){
                check_safe_area(next_r, next_c, h) ; 
            }
        }
    }
}
int main(){
    int max_h = 1 ; 
    int min_h = 100 ; 
    int max_safe = 1 ;
    scanf("%d", &N) ;

    for(int r = 0 ; r < N ; r++){
        for(int c = 0 ; c < N ; c++){
            scanf("%d", &height[r][c]) ; 
            max_h = max(height[r][c], max_h) ; 
            min_h = min(height[r][c], min_h) ; 
        }   
    }
    for(int h = min_h ; h <= max_h ; h++){
        init_visit() ; 
        int safe = 0 ;
        for(int r = 0 ; r < N ; r++){
            for(int c = 0 ; c < N ; c++){
                if(!visit[r][c] && height[r][c] > h){
                    check_safe_area(r, c, h) ; 
                    safe++ ; 
                }
            }   
        }
        max_safe = max(safe, max_safe) ; 
    }
    printf("%d", max_safe) ;
    return 0 ;

}