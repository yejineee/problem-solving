#include <iostream>
#include <vector>
using namespace std ;

vector<int> a_card(10, 0), b_card(10, 0) ; 
int a_win = 0, b_win = 0 ; 


int main(){

    for(int i = 0 ; i < 10 ; i++){
        scanf("%d", &a_card[i]) ; 
    }
    for(int i = 0 ; i < 10 ; i++){
        scanf("%d", &b_card[i]) ; 
    }
    for(int i = 0 ; i < 10 ; i++){
        int a = a_card[i] ; 
        int b = b_card[i] ; 
        if(a > b) a_win++ ;
        else if(a < b) b_win++ ;
    }

    if(a_win > b_win) printf("A") ; 
    else if(a_win < b_win) printf("B") ; 
    else printf("D") ; 

    return 0;
}