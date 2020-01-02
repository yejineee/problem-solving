#include <iostream>
#include <set>
#include <string>

using namespace std ;

int main(){
  int N ;
  set<string> in_company ; 
  scanf("%d", &N) ;
  while(N--){
    string name, status ; 
    cin >> name ;
    cin >> status ;
    if(status == "enter"){
      in_company.insert(name) ;
    }
    else{
      in_company.erase(name) ;
    }
  }
  for(set<string>::reverse_iterator rit = in_company.rbegin() ; rit != in_company.rend() ; rit++){
    printf("%s\n", (*rit).c_str()) ; 
  }
}