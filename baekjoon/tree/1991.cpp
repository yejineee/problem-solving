#include <iostream>
#include <map>
#include <string>
#include <unistd.h>
using namespace std ; 

map<char,char> left_child ;
map<char,char> right_child ;
string pre, in, post ; 
void preorder(char node){
  char l_child = left_child[node] ; 
  char r_child = right_child[node] ; 

  pre += node ; 

  if(l_child != '.'){
    preorder(l_child) ; 
  }
  if(r_child != '.'){
    preorder(r_child) ; 
  }
  return ;
}

void inorder(char node){
  char l_child = left_child[node] ; 
  char r_child = right_child[node] ; 
  if(l_child != '.'){
    inorder(l_child) ; 
  }

  in += node ; 

  if(r_child != '.'){
    inorder(r_child) ; 
  }
  return ;
}

void postorder(char node){
  char l_child = left_child[node] ; 
  char r_child = right_child[node] ; 
  if(l_child != '.'){
    postorder(l_child) ; 
  }
  if(r_child != '.'){
    postorder(r_child) ; 
  }

  post += node ; 

  return ;
}

int main(){
  int N ; 
  scanf("%d", &N) ;
  for(int i = 0 ; i <= N ; i++){
    char buf[10] ; 
    char node, l, r ; 
    fgets(buf, sizeof(buf), stdin) ;
    if(i == 0){
      continue ; 
    }
    string in (buf) ;
    node = in[0] ;
    left_child[node] = in[2] ;
    right_child[node] = in[4] ;
  }

  preorder('A') ;
  inorder('A') ;
  postorder('A') ;  

  printf("%s\n", pre.c_str()) ; 
  printf("%s\n", in.c_str()) ; 
  printf("%s\n", post.c_str()) ; 
  return 0 ; 
}