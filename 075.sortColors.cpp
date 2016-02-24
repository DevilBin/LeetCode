/*************************************************************************
	> File Name: 075.sortColors.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/24 13:59:27
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
    void sortColors(vector<int> & nums) {
        unsigned m, n, k;
        m = n = k = 0;
        for(unsigned i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) 
                m++;
            else if(nums[i] == 1)
                n++;
            else 
                k++;
        }
        for(unsigned i = 0; i < nums.size(); ++i) {
            if(i < m)
                nums[i] = 0;
            else if(i >= m && i < m + n)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

int main() {
    const int arr[] = {1, 1, 0, 2, 2, 0, 0, 1, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    test.sortColors(nums);

    for(unsigned i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
