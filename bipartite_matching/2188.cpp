#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

const int MAX_N = 200 ; 
vector<int> cow_prefer[MAX_N+1] ; 
bool visit[MAX_N+1] ; 
int barn[MAX_N+1] ; 

bool find_match(int cow){
    if(visit[cow]) return false ;
     visit[cow] = true ; 

    for(int i = 0; i < cow_prefer[cow].size() ; i++){
        int liked_barn = cow_prefer[cow][i] ;
        if(barn[liked_barn] == 0 || find_match(barn[liked_barn])){
            barn[liked_barn] = cow ;
            return true ; 
        }
    }
    return false ; 
}


int main(){
    int n_cow, n_barn, n_match = 0;
    scanf("%d %d", &n_cow, &n_barn) ; 
    for(int c = 1 ; c <= n_cow ; c++){
        int n, barn ;
        scanf("%d", &n); 
        while(n--){
            scanf("%d", &barn) ; 
            cow_prefer[c].push_back(barn) ;
        }
    }

    for(int c = 1 ; c <= n_cow ; c++){
        fill(visit+1, visit+1+n_cow, false) ; 
        if(find_match(c)) n_match++ ;
    }
    printf("%d", n_match) ; 
    return 0 ;
}