#include <iostream>
#include <queue>
using namespace std ;

const int MAX_POS = 100000 ; 
bool visit[MAX_POS+1] ; 
int t[MAX_POS+1] ; 
int find_min_time(int start, int dest){
    queue<int> q ;
    q.push(start); 
    visit[start] = true ; 

    while(!q.empty()){
        int here = q.front() ;
        q.pop() ; 
        if(here == dest) return t[here] ; 
        
        if(here+1 <= MAX_POS && !visit[here+1]){
            q.push(here+1) ; 
            t[here+1] = t[here]+1 ; 
            visit[here+1] = true ;
        }
        if(here-1 >= 0 && !visit[here-1]){
            q.push(here-1) ; 
            t[here-1] = t[here]+1 ; 
            visit[here-1] = true ;
        }
        if(here*2 <= MAX_POS && !visit[here*2]){
            q.push(here*2) ; 
            t[here*2] = t[here]+1 ; 
            visit[here*2] = true ;
        }

    }
    return -1 ; 
}



int main(){
    int N, K ; 
    scanf("%d %d", &N, &K) ;
    if(N < K)
        printf("%d", find_min_time(N, K)) ; 
    else{
        printf("%d", N-K) ;
    }

}