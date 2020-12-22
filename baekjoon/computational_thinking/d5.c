#include <stdio.h>

int result_num[100] ; 
int len = 0 ;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void Sort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}
void insert_num(int n){
  if(n <= 100){
    result_num[len] = n ;
  }
  len += 1 ;
}
int main(){
  int num1, num2 ;
  printf("2개의 숫자를 입력 ") ; 
  scanf("%d %d", &num1, &num2) ;
  for(int i = 1 ; i <= 100 ; i++){
    int ret_1 = num1 * i ; 
    int ret_2 = num2 * i ;
    if(ret_1 % num2 != 0){
      insert_num(ret_1) ;
    }
    if(ret_2 % num1 != 0){
      insert_num(ret_2) ; 
    }
  }
  Sort(result_num, len) ; 
  for(int i = 0 ; i < len; i++){
    if(result_num[i] != 0)
      printf("%d\n",result_num[i]) ; 
  }
}