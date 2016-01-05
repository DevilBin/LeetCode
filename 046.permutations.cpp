/*************************************************************************
	> File Name: 046.permutations.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 05 Jan 2016 02:13:41 PM CST
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
    vector<vector<int> > permute(vector<int> & nums) {
        vector<vector<int> > result;
        result.push_back(nums);
        while(result[0] != nextPermutation(nums)) {
            result.push_back(nums);
        }
        return result;
    }
    vector<int> nextPermutation(vector<int> & nums) {
        unsigned i = nums.size() - 1;
        unsigned j = nums.size() - 1;
        while(i > 0 && nums[i - 1] >= nums[i]) {
            --i;
        }
        if(i == 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            while(j >= i && nums[j] <= nums[i - 1]) {
                --j;
            }
            swap(nums[i - 1], nums[j]);
            sort(nums.begin() + i, nums.end());
        }
        return nums;
    }
    inline void swap(int & x, int & y) {
        int z; 
        z = x;
        x = y;
        y = z;
    }
};

int main() {
    const int arr[] = {1, 2, 3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<vector<int> > result = test.permute(nums);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
