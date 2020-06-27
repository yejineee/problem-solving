// 프로그래머스 고득점 kit - stack/queue 다리를 지나는 트럭
//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <list>
using namespace std;

int on_bridge_weight[100000000] ; 

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int time = 0 ; 
  int total_time = 0 ;
  list<int> truck_list (truck_weights.begin(), truck_weights.end()) ; 
  while(!truck_list.empty()){
    int truck_weight = truck_list.front() ; 
    if(on_bridge_weight[time] + truck_weight <= weight){
      for(int i = time; i < time+bridge_length ; i++){
        on_bridge_weight[i] += truck_weight ;
      }
      total_time = time+bridge_length ; 
      truck_list.pop_front() ; 
    }
    time++ ; 
  }
  return total_time+1;
}