/*************************************************************************
	> File Name: 062.uniquePaths.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/17 12:14:01
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
    int uniquePaths(int m, int n) {
        if(m < 1 || n < 1) {
            return 0;
        }
        else {
            vector<int> symbol(n, 1) ;
            for(int i = 1; i < m; ++i) {
                for(int j = 1; j < n; ++j) {
                    symbol[j] += symbol[j - 1];
                }
            }
            return symbol[n - 1];
        }
    }
};

int main() {
    Solution test;
    cout << test.uniquePaths(3, 7) << endl;
    return 0;
}
