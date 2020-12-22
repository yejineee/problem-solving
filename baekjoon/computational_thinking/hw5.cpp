#include <iostream>
#include <string>
using namespace std ;

const int L = 9 ; 
const int INF = 99999 ; 
int M[L+1][L+1] ; 
bool avail[L+1] ;  
int sum[L+1] ;  
string ret = "" ;

void print_M(){
  for(int i = 0 ; i <= L ; i++){
    printf("%4d",i) ;
  }
  printf("\n----------------------------------\n") ;
  for(int r = 1 ; r <= L ; r++){
    printf("%3d|", r) ;
    for(int c = 1 ; c <= L ; c++){
      printf("%4d", M[r][c]) ;
    }
    printf("\n") ;
  }
}
void solution() {
  for(int c = 1 ; c <= L ; c++){
    printf("=======%d번째========\n", c) ;
    int comp_min = INF ;
    int candidate = -1 ;
    for(int r = 1; r <= L ; r++){
      sum[r] -= M[r][c] ; 
      if(avail[r] == false) continue ;
      if (M[r][c] < comp_min ){
        comp_min = M[r][c] ; 
        candidate = r ;  
      }
      else if ( M[r][c] == comp_min){
        if(sum[r] > sum[candidate]){
          comp_min = M[r][c] ; 
          candidate = r ;
        }
      }
      printf("num = %d, comp_min = %d, candidate = %d \n", r, comp_min, candidate) ;
    }
    for(int i = 1 ; i <= L ; i++){
      printf("%d-(%d) | ",i,sum[i]) ; 
    }
    printf("\n%d 번째 : %d\n", c, candidate) ;
    ret += to_string(candidate) ; 
    avail[candidate] = false ;
  }
}
  

int main () {
  int input ; 
  scanf("%d", &input) ;
  while(input--){
    int n, in ;
    scanf("%d", &n) ; 
    for(int c = 1 ; c <= n ; c++){
      scanf("%d", &in) ;
      M[in][c] += 1 ;
      sum[in] = sum[in]+1 ; 
    }
  }
  for(int i = 1 ; i <= L ; i++){
    avail[i] = true ; 
  }
  print_M() ;
      for(int i = 1 ; i <= L ; i++){
        if(avail[i]== true)
          printf("%d-(%d) | ",i,sum[i]) ; 
    } 
  printf("\n") ; 
  solution() ;
  cout << ret << endl ;
}

