#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  stack <char> s ;
  string input ;
  cin >> input ;
  int stick = 0, idx = 0 ; 
  for(int i = 0 ; i < input.length() ; i++){
    if(input[i] == '('){
      if(input[i+1] == ')'){ 
        stick += s.size() ; 
        i++ ; 
      }else{
        s.push('(') ;
        stick++ ;
      }
    }else{
      s.pop() ; 
    }
  }

  cout << stick << endl ;

}