/*************************************************************************
	> File Name: 001.towSum.BruteForce.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/4 18:41:03
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> towSum(vector<int>& nums, int target) {
        vector<int> index;
        for(unsigned i = 0; i != nums.size(); ++i) {
            for(unsigned j = i; j != nums.size(); ++j) {
                if(i != j && (nums[i] + nums[j] == target)) {
                    index.push_back(i + 1);
                    index.push_back(j + 1);
                }
            }
        }
        return index;
    }
};

int main() {
    int target = 9;
    static const int arr[] = {2, 7, 11, 15};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<int> T = test.towSum(nums, target); 
    for(unsigned i = 0; i != T.size(); ++i) {
        cout << "index" << i + 1 << " = " << T[i] << '\n';
    }
    return 0;
}
