#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <stdlib.h>
using namespace std;

#define IDX(player) player-'A'
const int MAX_PLAYER = 26;
int nTagger[MAX_PLAYER];
int seat[MAX_PLAYER-1];
int nSeat;



void printResult(int lastTagger){
  for(int i = 0 ; i < nSeat ; i++){
    int player = seat[i];
    printf("%c %d\n", player, nTagger[IDX(player)]);
  }
  printf("%c %d", lastTagger, nTagger[IDX(lastTagger)]);
}
int getTargetSeat(int startSeat, int nMove){
  if(startSeat+nMove >= 0){
    return (startSeat+nMove) % nSeat;
  }else{
    return nSeat + (startSeat+nMove) % nSeat;
  }
}
bool isQuickPlayer(set<char> quickPlayerSet, int target){
  return quickPlayerSet.find((char)target) != quickPlayerSet.end();
}
int startGame(set<char> quickPlayerSet, vector<int> nMovePerGame){
  int startSeat = 0;
  int tagger = 'A';
  for(vector<int>::iterator it = nMovePerGame.begin(); it != nMovePerGame.end() ; it++){
    int nMove = *it;
    int targetSeat = getTargetSeat(startSeat, nMove);
    int target = seat[targetSeat];
    if(isQuickPlayer(quickPlayerSet, target)){
      nTagger[IDX(tagger)] += 1;
    }else{
      nTagger[IDX(target)] += 1;
      seat[targetSeat] = tagger;
      tagger = target;
    }
    // puts("---");
    // printResult(tagger);
    // printf("\ntarget : %c, 타겟 수 : %d, 술래 수 : %d\n", target, nTagger[IDX(tagger)], nTagger[IDX(target)]);
    startSeat = targetSeat;
  }
  return tagger;
}
void init(){
  nTagger[IDX('A')] = 1;
  for(int i = 0 ; i < nSeat ; i++){
    seat[i] = 'A'+i+1;
  }
}
void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  nSeat = numOfAllPlayers-1;
  set<char> quickPlayerSet (namesOfQuickPlayers, namesOfQuickPlayers+numOfQuickPlayers);
  vector<int> nMovePerGame (numOfMovesPerGame, numOfMovesPerGame+numOfGames);
  init();
  int lastTagger = startGame(quickPlayerSet, nMovePerGame );
  printResult(lastTagger);
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}