#include <iostream>
#include <list>
#include <unistd.h>
using namespace std ;
int N ;
int V[1001][1001] ;
list<int> main_path ;
list<int> path ;
void go (int y, int x) {
    path.push_back(x) ;
    V[y][x] -= 1 ;
    V[x][y] -= 1 ;
    for(int i = 1 ; i <= N ; i++){
        if(V[x][i] > 0){
            go(x, i) ;
            break ;
        }
    }
}

void
print_list(list<int> l){
    for(list<int>::iterator it = l.begin() ; it != l.end() ; it++){
        printf("%d ",*it) ;
    }
    printf("\n") ;
}
int 
main () {
    bool complete = false ;
    int num_v = 0 ;
    scanf("%d", &N) ;
    for(int y = 1 ; y <= N ; y++){
        for(int x = 1 ; x <= N ; x++){
            scanf("%d", &V[y][x]) ;
            num_v += V[y][x] ;
        }
    }
    for(int y = 1 ; y <= N && !complete ; y++){
        for(int x = 1 ; x <= N && !complete ; x++){
            if(V[y][x] > 0){
                main_path.push_back(y) ;
                go(y,x) ;
                main_path.insert(main_path.end(), path.begin(), path.end()) ;
                complete = true ;
            }
        }
    }
    if(main_path.front() != main_path.back()){
        puts("-1") ;
        return 0 ;
    }
    while(main_path.size() != num_v/2 + 1){
        complete = false ;
        for(list<int>::iterator it = main_path.begin() ; !complete && it != main_path.end() ; it++){
            int y = *it ;
            for(int x = 0 ; !complete && x <= N ; x++){
                if(V[y][x] > 0){
                    path.clear() ;
                    path.push_back(y) ;
                    go(y,x) ;
                    if(path.front() != path.back()){
                        puts("-1") ; 
                        return 0 ;
                    }
                    main_path.insert(it, path.begin(), --path.end()) ;
                    complete = true ;
                }
            }
        }
    }
    print_list(main_path) ;
}