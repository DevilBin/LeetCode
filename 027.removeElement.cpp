/*************************************************************************
	> File Name: 027.removeElement.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 25 Dec 2015 02:29:46 PM CST
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
    int removeElement(vector<int> & nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        else {
            for(unsigned i = 0; i < nums.size(); ++i) {
                if(val == nums[i]) {
                    nums.erase(nums.begin() + i);
                    i = i - 1;
                }
            }
            return nums.size();
        }
    }
};

int main() {
    const int arr[] = {1, 1, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    int n = test.removeElement(nums, 1);
    cout << n << endl;
    return 0;
}
