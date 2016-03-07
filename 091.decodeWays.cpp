/*************************************************************************
	> File Name: 091.decodeWays.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/7 14:25:20
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
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] < '1' || s[0] > '9') {
            return 0;
        }
        else {
            int dp0 = 1;
            int dp1 = 1;
            for(unsigned i = 1; i < s.size(); ++i) {
                int dp = 0;
                if(!isdigit(s[i]) || !isdigit(s[i - 1])) {
                    return 0;
                }
                int number = (s[i - 1] - '0') * 10 + s[i] - '0';
                if(number > 9 && number <= 26 ) {
                    dp = dp0;
                }
                if(s[i] != '0') {
                    dp += dp1;
                }
                if(dp == 0) {
                    return 0;
                }
                dp0 = dp1;
                dp1 = dp;
            }
            return dp1;
        }
    }
};

int main() {
    string s = "100";
    Solution test;
    
    cout << test.numDecodings(s) << endl;
    return 0;
}
