/*************************************************************************
	> File Name: 004.medianOfTwoSortedArrays.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sat 19 Nov 2016 09:37:55 AM CST
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
    double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
        if(0 == nums1.size())
            return meditate(nums2);
        if(0 == nums2.size())
            return meditate(nums1);
        return findNumber(nums1, nums2);
    }
    double meditate(vector<int> & nums) {
        size_t nums_size = nums.size();
        if(0 == nums_size) {
            return 0;
        }
        if(1 == nums_size) {
            return nums[0];
        }
        if(nums_size % 2 == 0) {
            return (nums[nums_size / 2 - 1] + nums[nums_size / 2]) / 2.0;
        }
        else {
            return nums[nums_size / 2];
        }
    }
    double findNumber(vector<int> & nums1, vector<int> & nums2) {
        vector<int> nums;
        size_t i = 0; size_t j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                ++i;
            }
            else {
                nums.push_back(nums2[j]);
                ++j;
            }
        }
        while(i < nums1.size()) {
            nums.push_back(nums1[i]);
            ++i;
        }
        while(j < nums2.size()) {
            nums.push_back(nums2[j]);
            ++j;
        }
        return meditate(nums);
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    
    Solution test;
    cout << test.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
