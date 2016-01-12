/*************************************************************************
	> File Name: 055.jumpGame.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 12 Jan 2016 10:54:09 AM CST
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
    bool canJump(vector<int> & nums) {
        max_jump = nums[0];
        for(i = 0; i < nums.size() - 1 && max_jump >= i; ++i) {
            if(nums[i] + i > max_jump)
                max_jump = nums[i] + i;
        }
        if(max_jump >= nums.size() - 1)
            return true;
        else
            return false;
    }
private:
    unsigned i;
    unsigned max_jump;
};

int main() {
    const int arr[] = {3, 2, 1, 1, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.canJump(nums) << endl;
    return 0;
}
