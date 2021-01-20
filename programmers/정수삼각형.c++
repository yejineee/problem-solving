#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_HEIGHT = 500;

int solution(vector<vector<int>> triangle) {
  int result = 0;
  int* maxNum = new int [1];
  maxNum[0] = triangle[0][0];
  for(int r = 0 ; r < triangle.size()-1; r++){
    int* tempMax = new int [triangle[r].size()+1];
    fill(tempMax, tempMax+triangle[r].size()+1, 0);
    for(int c = 0 ; c < triangle[r].size(); c++){
      int parent = maxNum[c];
      int& left = tempMax[c];
      int& right = tempMax[c+1];
      left = max(left, parent + triangle[r+1][c]);
      right = max(right, parent + triangle[r+1][c+1]);
    }
    delete maxNum;
    maxNum = tempMax;
  }   

  return *max_element(maxNum, maxNum+triangle.size());
}
