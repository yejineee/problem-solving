#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


long long collatz(long long num){
  return num % 2 == 0 ? num / 2 :  num * 3 + 1;
}

int solution(int input) {
  long long num = input;
  int answer = 0;
  while(num != 1){
    num = collatz(num);
    answer += 1;
    if(answer >= 500){
      return -1;
    }
  }
  return answer;
}