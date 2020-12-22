#include <iostream>
#include <list>
#include <iterator>
using namespace std ; 
list<char> slist ; 
list<char>::iterator cursor , it ; 

void edit(){
  char cmd , c ; 
  int N ; 
  cin >> N ; 
  while(N-- > 0){
    cin >> cmd ; 
    switch(cmd){
      case 'L':
        if(cursor != slist.begin()){
          cursor-- ; 
        }       
        break;
      case 'D':
        if(cursor != slist.end()){
          cursor++ ; 
        }      
        break;
      case 'B':
        if(cursor != slist.begin()){
          cursor-- ; 
          cursor = slist.erase(cursor) ;
        }    
        break;
      case 'P':
        cin >> c ; 
        slist.insert(cursor,c) ;
        
        break;
    }
  }

}
int main(){
  string s ;  
  cin >> s ; 

  for(int i=0; i < s.length() ;++i){
    slist.push_back(s[i]) ; 
  }
  cursor = slist.end(); 
  edit() ; 
  for(it = slist.begin() ; it != slist.end() ; it++){
      printf("%c",*it)  ;
  }
  cout << endl ;
  return 0 ;
}