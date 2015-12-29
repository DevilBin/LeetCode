/*************************************************************************
	> File Name: 034.searchForARange.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 29 Dec 2015 05:13:25 PM CST
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
    vector<int> searchRange(vector<int> & nums, int target) {
        if(nums.size() == 0) {
            vector<int> result;
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else {
            vector<int> result;
            int low = 0; 
            int flag = -1;
            int high = static_cast<int>(nums.size() - 1);
            while(low <= high) {
                int mid = (low + high) / 2;
                if(nums[mid] == target) {
                    flag = mid;
                    break;
                }
                else if(target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            if(flag == -1) {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
            else {
                low = 0; high = flag - 1;
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if(nums[mid] == target) {
                        high = mid - 1;
                    }
                    else
                        break;
                }
                while(high >= 0 && nums[high] == nums[high + 1]) {
                    high--;
                }
                result.push_back(high + 1);
                
                low = flag + 1; high = static_cast<int>(nums.size() - 1);
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if(nums[mid] == target) {
                        low = mid + 1;
                    }
                    else 
                        break;
                }
                while(low <= high && nums[low] == nums[low - 1]) {
                    low++;
                }
                result.push_back(low - 1);

                return result;
            }
        }
    }
};

int main() {
    const int arr[] = {1, 2};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<int> result = test.searchRange(nums, 1);
    for(unsigned i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
