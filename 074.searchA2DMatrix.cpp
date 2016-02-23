/*************************************************************************
	> File Name: 074.searchA2DMatrix.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/23 11:39:22
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
const int N = 3;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        low = 0;
        high = matrix.size() - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(target == matrix[mid][0]) {
                return true;
            }
            else if(target < matrix[mid][0]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(high < 0) {
            return false;
        }
        else {
            row = high;
            low = 0;
            high = matrix[row].size() - 1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(target == matrix[row][mid]) {
                    return true;
                }
                else if(target < matrix[row][mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            return false;
        }
    }
private:
    int row, low, mid, high;
};

int main() {
    const int arr[N][N + 1] = {{ 1,  3,  5,  7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 50}};
    vector<vector<int> > matrix;

    for(unsigned i = 0; i < N; ++i) {
        vector<int> temp;
        for(unsigned j = 0; j < N + 1; ++j) {
            temp.push_back(arr[i][j]);
        }
        matrix.push_back(temp);
    }

    Solution test;
    cout << test.searchMatrix(matrix, 16) << endl;
    return 0;
}
