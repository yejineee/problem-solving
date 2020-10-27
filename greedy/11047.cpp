#include <iostream>
#include <list>
using namespace std ;
list<int> coinList;
int remain;


int findMinimumCoin(){
  int count = 0;
  for(list<int>::iterator it=coinList.begin(); it != coinList.end(); it++){
    int coin = *it;
    if(remain >= coin){
      count += remain / coin;
      remain %= coin;
    }
  }
  return count;
}
int main(){
  int n ; 
  scanf("%d %d", &n, &remain);
  while(n--){
    int coin;
    scanf("%d", &coin);
    coinList.push_front(coin);
  }
  printf("%d", findMinimumCoin());
}