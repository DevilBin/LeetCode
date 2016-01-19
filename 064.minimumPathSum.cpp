/*************************************************************************
	> File Name: 064.minimumPathSum.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/19 13:02:15
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
    int minPathSum(vector<vector<int> > & grid) {
        if(grid.size() == 0) {
            return 0;
        }
        else {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> symbol(n + 1, 0);

            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(i == 0) {
                        symbol[j + 1] = symbol[j] + grid[i][j];
                    }
                    else if(j == 0) {
                        symbol[j + 1] += grid[i][j];
                    }
                    else {
                        if(symbol[j + 1] > symbol[j]) {
                            symbol[j + 1] = symbol[j] + grid[i][j];
                        }
                        else {
                            symbol[j + 1] += grid[i][j];
                        }
                    }
                }
            }
            return symbol[n];
        }
    }
};

int main() {
    const int arr[N][N] = {{2, 1, 3, 1},
                           {3, 1, 0, 2},
                           {2, 4, 1, 1},
                           {4, 1, 2, 4}};
    vector<vector<int> > obstacleGrid;

    for(int i = 0; i < N; ++i) {
        vector<int> temp;
        for(int j = 0; j < N; ++j) {
            temp.push_back(arr[i][j]);
        }
        obstacleGrid.push_back(temp);
    }

    Solution test;
    cout << test.minPathSum(obstacleGrid) << endl;
    return 0;
}
