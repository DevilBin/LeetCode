/*************************************************************************
	> File Name: 053.maximumSubarray.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/10 16:14:29
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

class Solution {
public:
    int maxSubArray(vector<int> & nums) {
        if(nums.size() == 0)
            return 0;
        int newsum = nums[0];
        int max_result = nums[0];
        for(unsigned i = 1; i < nums.size(); ++i) {
            newsum = max(newsum + nums[i], nums[i]); 
            max_result = max(max_result, newsum);
        }
        return max_result;
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }
};

int main() {
    const int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.maxSubArray(nums) << endl;
    return 0;
}
