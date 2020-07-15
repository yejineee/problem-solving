#include <iostream>
#include <vector>
using namespace std ;
vector<int> bar, desc_bar ; 


int find_idx(int key){
    int start = 0, end = desc_bar.size() ; 
    while(start < end){
        int mid = (start+end) / 2 ; 
        if(desc_bar[mid] <= key){
            end = mid ;
        }
        else{
            start = mid+1 ; 
        }
    }
    return end ; 
}

int main(){
    int N ;
    scanf("%d", &N) ;
    while(N--){
        int b; 
        scanf("%d", &b) ;
        bar.push_back(b) ; 
    }
    for(const auto& b : bar){
        int idx = find_idx(b) ; 
        if(idx == desc_bar.size()){
            desc_bar.push_back(b) ; 
        }
        else{
            desc_bar[idx] = b ; 
            desc_bar.erase(desc_bar.begin()+idx+1, desc_bar.end()) ; 
        }
 
    }
    printf("%lu", desc_bar.size() ) ; 
    return 0 ;
}