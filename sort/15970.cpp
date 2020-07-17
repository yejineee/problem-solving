#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std ;

const int MAX_N = 5000 ;
map<int, vector<int> > point ;

int compute_sum_len(){
    int len = 0 ;
    for(int x = 0 ; x < point.size() ; x++){
        vector<int> color = point[x] ;
        sort(color.begin(), color.end()) ; 
        for(int i = 0 ; i < color.size() ; i++){
            if(i == 0){
                len += color[1]-color[0]; 
            }
            else if(i == color.size()-1){
                len += color[i]-color[i-1] ; 
            }
            else{
                len += min(color[i]-color[i-1], color[i+1]-color[i]) ;
            }
        }
    }
    return len ; 
}
int main(){
    int N ;
    scanf("%d", &N) ; 
    while(N--){
        int p, c ; 
        scanf("%d %d", &p, &c) ;
        point[c].push_back(p) ; 
    }
    
    printf("%d", compute_sum_len()) ; 
    return 0 ;
}