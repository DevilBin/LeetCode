/*************************************************************************
	> File Name: 059.spiralMatrixII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/14 10:59:51
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int top = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        vector<vector<int> > matrix;
        
        for(int i = 0; i < n; ++i) {
            vector<int> temp;
            for(int j = 0; j < n; ++j) {
                temp.push_back(0);
            }
            matrix.push_back(temp);
        }

        int index = 1;
        while(true) {
            if(top <= down) {
                for(int i = left; i <= right; ++i) {
                    matrix[top][i] = index;
                    index++;
                }
                top++;
            }
            else break;
           
            if(left <= right) {
                for(int i = top; i <= down; ++i) {
                    matrix[i][right] = index;
                    index++;
                }
                right--;
            }
            else break;

            if(top <= down) {
                for(int i = right; i >= left; --i) {
                    matrix[down][i] = index;
                    index++;
                }
                down--;
            }
            else break;

            if(left <= right) {
                for(int i = down; i >= top; --i) {
                    matrix[i][left] = index;
                    index++;
                }
                left++;
            }
            else break;
        }
        return matrix;
    }
};

int main() {
    Solution test;
    vector<vector<int> > result = test.generateMatrix(9);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << setw(2) << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
