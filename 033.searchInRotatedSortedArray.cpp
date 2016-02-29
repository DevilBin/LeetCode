/*************************************************************************
	> File Name: 033.searchInRotatedSortedArray.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/29 10:51:24
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
    int search(vector<int> & nums, int target) {
        if(nums.size() == 0) {
            return -1;
        } 
        else {
            int low = 0;
            int mid = 0;
            int high = nums.size() - 1;
            while(low <= high) {
                mid = (low + high) / 2;
                if(target == nums[mid] ) {
                    return mid;
                }
                if(nums[mid] >= nums[low]) {
                    if(nums[low] <= target && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else {
                    if(nums[mid] < target && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
            return -1;
        }
    }
};

int main() {
    const int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.search(nums, 3) << endl;
    return 0;
}
