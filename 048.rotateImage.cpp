/*************************************************************************
	> File Name: 048.rotateImage.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Thu 07 Jan 2016 10:47:22 AM CST
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
const int N = 4;

class Solution {
public:
    void rotate(vector<vector<int> > & matrix) {
        unsigned n = matrix.size() - 1;
        for(unsigned i = 0; i < matrix.size(); ++i) {
            for(unsigned j = 0; j < matrix[i].size() - i; ++j) {
                swap(matrix[i][j], matrix[n - j][n - i]);
            }
        }
        for(unsigned i = 0; i < matrix.size() / 2; ++i) {
            for(unsigned j = 0; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[n - i][j]);
            }
        }
    }
};

int main() {
    const int arr[4][4] = {{1, 2, 4, 7},
                           {3, 2, 9, 4},
                           {4, 7, 5, 6},
                           {7, 2, 3, 4}};
    vector<vector<int> > result;

    for(int i = 0; i < N; i++) {
        vector<int> temp;
        for(int j = 0; j < N; ++j) {
            temp.push_back(arr[i][j]);
        }
        result.push_back(temp);
    }

    Solution test;
    test.rotate(result);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
