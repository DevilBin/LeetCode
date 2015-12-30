/*************************************************************************
	> File Name: 035.searchInsertPosition.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Wed 30 Dec 2015 11:44:47 AM CST
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
    int searchInsert(vector<int> & nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        else {
            int low = 0;
            int high = static_cast<int> (nums.size() - 1);
            while(low <= high) {
                int mid = (low + high) / 2;
                if(nums[mid] == target) {
                    low = mid;
                    break;
                }
                else if(nums[mid] > target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            return low;
        }
    }
};

int main() {
    const int arr[] = {1, 3, 5};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.searchInsert(nums, 3) << endl;
    return 0;
}
