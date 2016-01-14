/*************************************************************************
	> File Name: 054.spiralMatrix.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/11 11:28:41
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <climits>

using namespace std;
const int N = 5;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > & matrix) {
        vector<int> result;
        if(matrix.size() == 0) {
            return result;
        }
        else {
            int top = 0;
            int down = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
    
            while(true) {
                // top: left --> right
                if(top <= down) {
                    for(int i = left; i <= right; ++i) {
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                }
                else break;
                // right: top --> down
                if(left <= right) {
                    for(int i = top; i <= down; ++i) {
                        result.push_back(matrix[i][right]);
                    }
                    right--;
                }
                else break;
                // down: right --> left
                if(top <= down) {
                    for(int i = right; i >= left; --i) {
                        result.push_back(matrix[down][i]);
                    }
                    down--;
                }
                else break;
                // left: down --> top
                if(left <= right) {
                    for(int i = down; i >= top; --i) {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
                else break;
            }
            return result;
        }
    }
};

int main() {
    const int arr[N][N] = {{1, 2, 4, 7, 2},
                           {3, 2, 9, 4, 1},
                           {4, 7, 5, 6, 4},
                           {7, 2, 3, 4, 9},
                           {2, 8, 5, 1, 7}};
    vector<vector<int> > matrix;

    for(int i = 0; i < N; i++) {
        vector<int> temp;
        for(int j = 0; j < N; ++j) {
            temp.push_back(arr[i][j]);
        }
        matrix.push_back(temp);
    }

    Solution test;
    vector<int> result = test.spiralOrder(matrix);
    for(unsigned i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
