/*************************************************************************
	> File Name: 066.plusOne.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/20 12:52:17
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
    vector<int> plusOne(vector<int> & digits) {
        int c = 1;
        vector<int> result;
        if(digits.size() == 0) 
            return result;
        for(int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + c;
            if(sum > 9) {
                c = 1;
                result.push_back(sum % 10);
            }
            else {
                c = 0;
                result.push_back(sum);
            }
        }
        if(c > 0) {
            result.push_back(c);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    const int arr[] = {};
    vector<int> digits(arr, arr + sizeof(arr) / sizeof(arr[0]));
    
    Solution test;
    vector<int> result = test.plusOne(digits);
    for(unsigned i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
