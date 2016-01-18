/*************************************************************************
	> File Name: 063.uniquePathsII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/18 13:03:32
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
    int uniquePathsWithObstacles(vector<vector<int> > & obstacleGrid) {
        if(obstacleGrid.size() == 0) {
            return 0;
        }
        else {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<int> symbol(n + 1, 0);

            if(obstacleGrid[0][0] == 1) {
                return 0;
            }
            symbol[1] = 1;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(obstacleGrid[i][j] == 0) {
                        symbol[j + 1] += symbol[j];
                    }
                    else {
                        symbol[j + 1] = 0;
                    }
                }
            }
            return symbol[n];
        }
    }
};

int main() {
    const int arr[N][N] = {{0, 0, 0, 0},
                           {0, 1, 0, 0},
                           {0, 0, 0, 1},
                           {0, 0, 0, 0}};
    vector<vector<int> > obstacleGrid;

    for(int i = 0; i < N; ++i) {
        vector<int> temp;
        for(int j = 0; j < N; ++j) {
            temp.push_back(arr[i][j]);
        }
        obstacleGrid.push_back(temp);
    }

    Solution test;
    cout << test.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
