#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std ;
const int MAX_L = 30 ; 
int dir[6][3] = {{0,0,1}, {0,1,0} , {0,0,-1},{0,-1,0}, {1,0,0}, {-1,0,0},} ; 
int L, R, C ; 
char building[MAX_L][MAX_L][MAX_L] ;
int moved[MAX_L][MAX_L][MAX_L] ;

int check_shortest_path(tuple<int, int, int> start){
    queue<tuple<int,int,int> > Q ; 
    Q.push(start) ; 

    while(!Q.empty()){
        int l, r, c ;
        tie(l, r, c) = Q.front(); 
        Q.pop() ; 
        for(int i = 0 ; i < 6 ; i++){
            int nl = l + dir[i][0] ;
            int nr = r + dir[i][1] ;
            int nc = c + dir[i][2] ; 
            if(nl >= 0 && nl < L && nr >= 0 && nr < R && nc >= 0 && nc < C ){
                if(building[nl][nr][nc] != '#' && moved[nl][nr][nc] == 0){
                    moved[nl][nr][nc] = moved[l][r][c]+1 ; 
                    if(building[nl][nr][nc] == 'E'){
                        return moved[nl][nr][nc];
                    }
                    Q.push(make_tuple(nl, nr, nc)) ; 
                }
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    tuple<int,int,int> start_pos ; 
    while(1){
        cin >> L >> R >> C ; 
        if(L == 0 && R == 0 && C == 0) break ;
        string status ; 
        for(int l = 0 ; l < L ; l++){
            for(int r = 0 ; r < R ; r++){
                cin >> status ;
                memset(moved[l]+r, 0, sizeof(moved[0][0][0])*C) ;  
                for(int c = 0 ; c < C ; c++){
                    building[l][r][c] = status[c] ; 
                    if(building[l][r][c] == 'S'){
                        start_pos = make_tuple(l,r,c) ; 
                    }
                }
            }
        }

        int min_move = check_shortest_path(start_pos) ; 
        if(min_move == -1) puts("Trapped!") ;
        else printf("Escaped in %d minute(s).\n", min_move) ; 
        
    }
}