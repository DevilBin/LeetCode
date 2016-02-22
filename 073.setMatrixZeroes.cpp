/*************************************************************************
	> File Name: 073.setMatrixZeroes.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/22 14:58:59
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
const int N = 4;

class Solution {
public:
    void setZeroes(vector<vector<int> > & matrix) {
        vector<vector<int> > columnRow;
        for(unsigned i = 0; i < matrix.size(); ++i) {
            for(unsigned j = 0; j < matrix[i].size(); ++j) {
                vector<int> temp;
                if(matrix[i][j] == 0) {
                    temp.push_back(i);
                    temp.push_back(j);
                    columnRow.push_back(temp);
                }
            }
        }
        for(unsigned i = 0; i < columnRow.size(); ++i) {
            for(unsigned j = 0; j < matrix[columnRow[i][0]].size(); ++j) {
                matrix[columnRow[i][0]][j] = 0;
            }
            for(unsigned k = 0; k < matrix.size(); ++k) {
                matrix[k][columnRow[i][1]] = 0;
            }
        }
    }
};

int main() {
    const int arr[N][N + 1] = {{1, 2, 3, 4, 5},
                               {3, 4, 2, 1, 2},
                               {1, 1, 0, 2, 1},
                               {2, 4, 2, 1, 9}};
    vector<vector<int> > matrix;

    for(int i = 0; i < N; ++i) {
        vector<int> temp;
        for(int j = 0; j < N + 1; ++j) {
            temp.push_back(arr[i][j]);
        }
        matrix.push_back(temp);
    }

    Solution test;
    test.setZeroes(matrix);
    
    for(unsigned i = 0; i < matrix.size(); ++i) {
        for(unsigned j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
