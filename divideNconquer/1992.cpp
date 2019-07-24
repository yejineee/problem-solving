
#include <iostream>
#include <string>

using namespace std;

#define MAX 64
#define TRUE 1
#define FALSE 0
char matrix[MAX][MAX];

void compress(int x0, int y0, int size)
{

  char testcase = matrix[y0][x0];
  int flag = TRUE;
  for (int y = y0; y < y0+size; y++){
    for (int x = x0; x < x0+size; x++){
      if (matrix[y][x] != testcase){
        flag = FALSE;
        break;
      }
    }
  }
  if (flag == TRUE){
    printf("%c", testcase);
  }
  else{
    size /= 2 ; 
    printf("(");
    compress(x0, y0, size);         // 2사분면, 왼쪽 위
    compress(x0 + size, y0, size);     // 1사분면, 오른쪽 위
    compress(x0, y0 + size, size);     // 3사분면, 왼쪽 아래
    compress(x0 + size, y0 + size, size); // 4사분면, 오른쪽 아래
    printf(")");
  }
  return;
}
int main()
{
  int length;
  string input;
  scanf("%d", &length);
  for (int y = 0; y < length; y++){
    for (int x = 0; x < length; x++){
      cin >> matrix[y][x] ; 
    }
  }
  compress(0, 0, length);
  printf("\n") ; 
}
