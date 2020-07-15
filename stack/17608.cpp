#include <iostream>
#include <stack>
using namespace std ;
stack<int> bar ; 

int main(){
    int N ; 
    scanf("%d", &N) ; 
    for(int i = 0 ; i < N ; i++){
        int b ; 
        scanf("%d", &b) ; 
        while(!bar.empty()){
            if(bar.top() < b){
                bar.pop() ;
            }
            else if(bar.top() > b){
                bar.push(b) ;
                break ; 
            }
            else{
                break ;
            }
        }
        if(bar.empty()) bar.push(b) ; 
    }

    printf("%lu", bar.size()) ;
    return 0 ;
}