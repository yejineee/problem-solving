#include <iostream>
#include <map>
#include <vector>
using namespace std ;
vector <int> result ;
map <string, int> closet ;

int main() {
  int T, n ;
  scanf("%d", &T) ; 
  while(T--){
    int ret = 1 ;
    closet.clear() ;
    scanf("%d",&n) ;
    while(n--){
      string name, category ;
      cin >> name ; 
      cin >> category ;
      if(closet.find(category) != closet.end()){
        closet.find(category)->second += 1 ;
      }
      else{
        closet[category] = 1 ;
      }
    }
    for(map<string,int>::iterator it = closet.begin() ; it != closet.end() ; it++){
      ret *= (it->second) + 1 ;
    }
    ret -= 1 ;
    result.push_back(ret) ;
  }
  for(vector<int>::iterator it = result.begin() ; it != result.end() ; it++){
    printf("%d\n",*it) ;
  }
}

