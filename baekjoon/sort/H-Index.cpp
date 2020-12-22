/*
프로그래머스 고득점 kit - 정렬
https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp#
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int h ; 
bool greater_equal_to(int i)
{
  if( i >= h){
    return true ; 
  }
  return false ;  
}
int solution(vector<int> citations) {
    int max_h = -1;
    int n = citations.size() ;
    h = n/2 ;
    sort(citations.begin(), citations.end()) ; 
    while(1){
        if(h <= count_if(citations.begin(), citations.end(), greater_equal_to)){
          max_h = h ; 
          h++ ; 
        }
        else if(max_h != -1) break ; 
        else h-- ; 
    }
    return max_h;
}