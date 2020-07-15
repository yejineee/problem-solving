#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std ;
const int MAX_N = 100000 ;
int start, fin ;
int N ;
vector<bool> visit ;
vector< pair<int, int> > path[MAX_N+1] ;

void find_min_move(int room, int sum_move, int max_move){
    visit[room] = true ;
    if(room == fin){
        printf("%d",sum_move-max_move) ; 
        return ;
    }
    for(int i = 0 ; i < path[room].size(); i++){
        int next = path[room][i].first ;
        int move = path[room][i].second ;
        if(!visit[next]){
            find_min_move(next, sum_move+move, max(max_move, move)) ; 
        }
    }
}
int main(){
    scanf("%d %d %d", &N, &start, &fin) ;
    visit.assign(N+1, false) ;

    for(int i = 0 ; i < N-1 ; i++){
        int a, b, len ;
        scanf("%d %d %d", &a, &b, &len) ;
        path[a].push_back(make_pair(b, len)) ; 
        path[b].push_back(make_pair(a, len)) ; 
    }
    find_min_move(start, 0, 0) ;
 
    return 0 ;
}
