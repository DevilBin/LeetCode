/*************************************************************************
	> File Name: 026.removeDuplicatesFromSortedArray.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/24 14:38:55
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
    int removeDuplicates(vector<int> & nums) {
        if(nums.size() == 0) {
            return 0;
        }
        else if(nums.size() == 1) {
            return 1;
        }
        else {
            int lastElement = nums[0];
            for(unsigned i = 1; i < nums.size(); ++i) {
                if(lastElement == nums[i]) {
                    nums.erase(nums.begin() + i);
                    i = i - 1;
                }
                else {
                    lastElement = nums[i];
                }
            }
            return nums.size();
        }
    }
};

int main() {
    const int arr[] = {1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 5, 6, 7};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    int n = test.removeDuplicates(nums);
    cout << n << endl;
    return 0; 
}

