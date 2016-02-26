/*************************************************************************
	> File Name: 078.subsets.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/26 10:15:42
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
    vector<vector<int> > subsets(vector<int> & nums) {
        vector<int> temp;
        vector<vector<int> > result;
        for(unsigned i = 0; i <= nums.size(); ++i) {
            findCombine(nums.size(), 0, i, temp, result, nums);
        }
        for(unsigned i = 0; i < result.size(); ++i) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
    void findCombine(int n, int start, int k, vector<int> & temp, vector<vector<int> > & result, vector<int> nums) {
        if(k == 0) {
            result.push_back(temp);
        } else {
            for(int i = start; i < n - k + 1; ++i) {
                temp.push_back(nums[i]);
                findCombine(n, i + 1, k - 1, temp, result, nums);
                temp.pop_back();
            }
        }
    }
};

int main() {
    const int arr[] = {4, 1, 0};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<vector<int> > result = test.subsets(nums);

    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
