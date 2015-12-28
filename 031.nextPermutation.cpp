/*************************************************************************
	> File Name: 031.nextPermutation.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Mon 28 Dec 2015 01:27:50 PM CST
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
    void nextPermutation(vector<int> & nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return;
        }
        else {
            unsigned i, j;
            i = nums.size() - 1;
            while(i > 0) {
                if(nums[i - 1] < nums[i]) {
                    break;
                }
                --i;
            }
            if(i == 0) {
                reverse(nums.begin(), nums.end());
            }
            else {
                j = nums.size() - 1;
                while(j >= i && nums[j] <= nums[i - 1]) {
                    --j;
                }
                swap(nums[i - 1], nums[j]);
                sort(nums.begin() + i, nums.end());
            }
            for(unsigned i = 0; i < nums.size(); ++i) {
                cout << nums[i] << ' ';
            }
        }
    }
    inline void swap(int & x, int & y) {
        int z; 
        z = x;
        x = y;
        y = z;
    }
};

int main() {
    const int arr[] = {3, 2, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    test.nextPermutation(nums);
    return 0;
}
