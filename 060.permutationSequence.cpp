/*************************************************************************
	> File Name: 060.permutationSequence.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 15 Jan 2016 11:58:52 AM CST
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
    string getPermutation(int n, int k) {
        string result;
        vector<char> nums;
        vector<int> fac(n, 1);

        for(int i = 0; i < n; ++i) {
            nums.push_back(i + '1');
        }
        for(int i = 1; i < n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        k--;
        for(int i = n - 1; i >= 0; --i) {
            int j = k / fac[i];
            result += nums[j];
            k %= fac[i];
            nums.erase(nums.begin() + j);
        }
        return result;
    }
};

int main() {
    Solution test;
    cout << test.getPermutation(4, 9) << endl;
    return 0;
}
