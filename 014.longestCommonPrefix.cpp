/*************************************************************************
	> File Name: 014.longestCommonPrefix.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/14 13:52:31
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
    string longestCommonPrefix(vector<string> & strs) {
        if(strs.size() == 0) 
            return "";
        else if(strs[0].size() == 0)
            return "";
        else {
            for(unsigned i = 0; i < strs[0].size(); ++i) {
                unsigned j = 1;
                while(j < strs.size() && strs[0][i] == strs[j][i]) {
                    j++;
                }
                if(j == strs.size()) {
                    stemp = strs[0][i];
                    s += stemp;
                }
                else
                    break;
            }
            return s;
        }
    }
private:
    string s;
    string stemp;
};

int main() {
    string str[] = {"abc", "acd"};
    vector<string> strs(str, str + sizeof(str) / sizeof(str[0]));

    Solution test;
    cout << test.longestCommonPrefix(strs) << endl;
    return 0;
}
