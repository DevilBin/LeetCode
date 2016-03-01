/*************************************************************************
	> File Name: 081.searchInRotatedSortedArrayII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/1 11:27:22
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
    bool search(vector<int> & nums, int target) {
        if(nums.size() == 0) {
            return false;
        }
        else {
            int low = 0;
            int mid = 0;
            int high = nums.size() - 1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(target == nums[mid]) {
                    return true;
                }
                if(nums[mid] > nums[low]) {
                    if(nums[low] <= target && target < nums[mid]) 
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else if(nums[mid] == nums[low]) {
                    low = low + 1;
                }
                else {
                    if(nums[mid] < target && target <= nums[high]) 
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            return false;
        }
    }
};

int main() {
    const int arr[] = {3, 1, 1, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.search(nums, 1) << endl;
    return 0;
}
