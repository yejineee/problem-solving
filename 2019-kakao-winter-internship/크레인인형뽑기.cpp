#include <string>
#include <vector>
using namespace std;

vector<int> basket;
const int EMPTY = 0;
int nLine;
int nPopped;


void pushOrPopToBasket(vector<vector<int>> board, int toy){
  if(!basket.empty() && basket.back() == toy){
    basket.pop_back();
    nPopped += 2;
  }else{
    basket.push_back(toy);
  }
}

void moveAndPopToy(int column, vector<vector<int>> &board){
  for(int r = 0; r < nLine; r++){
    if(board[r][column] == EMPTY){
      continue;
    }
    pushOrPopToBasket(board, board[r][column]);
    board[r][column] = EMPTY;
    break;
  }
}


int solution(vector<vector<int>> board, vector<int> moves){
  nLine = board.size();
  int nMove = moves.size();
  for(int i = 0; i < nMove; i++){
    int targetColumn = moves[i]-1;
    moveAndPopToy(targetColumn, board);
  }

  return nPopped;
}

