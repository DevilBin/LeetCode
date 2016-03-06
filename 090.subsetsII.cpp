/*************************************************************************
	> File Name: 090.subsetsII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/6 17:42:19
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
    vector<vector<int>> subsetsWithDup(vector<int> & nums) {
        vector<int> temp;
        vector<vector<int>> result;
        for(unsigned i = 0; i <= nums.size(); ++i) {
            findCombine(nums.size(), 0, i, temp, result, nums);
        }
        return result;
    }
    void findCombine(int n, int start, int k, vector<int> & temp, vector<vector<int>> & result, vector<int> nums) {
        if(k == 0) {
            if(result.size() == 0) {
                result.push_back(temp);
            }
            else {
                vector<int> tempCopy = temp;
                sort(tempCopy.begin(), tempCopy.end());
                for(unsigned i = 0; i < result.size(); ++i) {
                    if(result[i] == tempCopy) return;
                }
                result.push_back(tempCopy);
            }
        }
        else {
            for(int i = start; i < n - k + 1; ++i) {
                temp.push_back(nums[i]);
                findCombine(n, i + 1, k - 1, temp, result, nums);
                temp.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {4, 4, 4, 1, 4};
    Solution test;
    
    vector<vector<int>> result = test.subsetsWithDup(nums);
    for(const auto &x : result) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    return 0;
}
