#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

const int MAX_N = 100000 ;
vector<int> edge[MAX_N+1] ; 
int parent[MAX_N+1]  ; 

void find_parent(){
    parent[1] = 1; 
    queue<int> q ; 
    q.push(1) ; 

    while(!q.empty()){
        int p = q.front() ; 
        q.pop() ; 
        for(const auto& v : edge[p]){
            if(!parent[v]){
                parent[v] = p ;
                q.push(v) ; 
            }
        }
    }
}
int main(){
    int N, u, v;
    scanf("%d", &N) ;
    for(int i = 0; i < N-1 ; i++){
        scanf("%d %d", &u, &v) ; 
        edge[u].push_back(v) ; 
        edge[v].push_back(u) ; 
    }
    find_parent() ; 
    for(int i = 2 ; i <= N ; i++){
        printf("%d\n", parent[i]) ; 
    }
}
