/*************************************************************************
	> File Name: 096.uniqueBinarySearchTrees.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/11 22:42:56
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
    int numTrees(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 1;

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                nums[i] += nums[j] * nums[i - 1 - j];
            }
        }
        return nums[n];
    }
};

int main() {
    Solution test;
    cout << test.numTrees(5) << endl;
    return 0;
}
