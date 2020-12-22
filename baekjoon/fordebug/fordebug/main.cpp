#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <utility>
using namespace std ;
int start_x, start_y, fin_x, fin_y, n_pos ;
vector<pair<int, int> > pos ;
bool comp(pair<int, int> a, pair<int, int> b){
    int a_dist = abs(a.first-start_x) + abs(a.second-start_y) ;
    int b_dist = abs(b.first-start_x) + abs(b.second-start_y) ;
    return a_dist < b_dist ;
}
bool go_festival(int here, vector<bool> visit){
    visit[here] = true ;
    printf("--- ( %d , %d ) ---\n", pos[here].first, pos[here].second) ;
    if(pos[here].first == fin_x && pos[here].second == fin_y){
        return true ;
    }

    for(int i = 1 ; i < n_pos ;  i++){
        int dist = abs(pos[here].first - pos[i].first) + abs(pos[here].second - pos[i].second) ;
        printf("%d - (%d, %d), dist : %d\n",i, pos[i].first, pos[i].second, dist );
        if(!visit[i] && dist <= 1000){
            printf("go\n") ;
           if(go_festival(i, visit)){
               return true ;
           }
        }
    }
    return false ;
}
int main(){
    int T, n_store, x, y ;
    scanf("%d", &T) ;
    while(T--){
        scanf("%d", &n_store) ;
        pos.clear() ;
        n_pos = n_store+2 ;
        for(int i = 0 ; i < n_pos ; i++){
            scanf("%d %d", &x, &y) ;
            pos.push_back(make_pair(x,y)) ;
        }
        start_x = pos.front().first ;
        start_y = pos.front().second ;
        fin_x = pos.back().first ;
        fin_y = pos.back().second ;
        vector<bool> visit(pos.size(), false) ;
        sort(pos.begin(), pos.end(), comp) ;
        puts("============================") ;
        if(go_festival(0, visit)){
            puts("happy") ;
        }
        else{
            puts("sad") ;
        }
        puts("-------------------------") ;
        for(const auto& p : pos){
            printf("%d %d\n", p.first, p.second) ;
        }
    }

}
