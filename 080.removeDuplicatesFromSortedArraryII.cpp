/*************************************************************************
	> File Name: 080.removeDuplicatesFromSortedArraryII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/28 11:11:21
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
    int removeDuplicates(vector<int> & nums) {
        if(nums.size() == 0) {
            return 0;
        }
        else if(nums.size() == 1) {
            return 1;
        }
        else {
            int lastElement = nums[0];
            int secondElement = nums[1];
            for(unsigned i = 2; i < nums.size(); ++i) {
                if(lastElement == nums[i] && lastElement == secondElement) {
                    nums.erase(nums.begin() + i);
                    i = i - 1;
                }
                else {
                    lastElement = nums[i];
                    secondElement = nums[i - 1];
                }
            }
            return nums.size();
        }
    }
};

int main() {
    const int arr[] = {1, 1, 1, 2, 2, 3, 3, 3};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.removeDuplicates(nums) << endl;
    return 0;
}
