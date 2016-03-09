/*************************************************************************
	> File Name: 093.restoreIpAddresses.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/9 12:17:50
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
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> resultTemp;
        if(s.size() == 0) {
            return result;
        }
        else {
            findIp(s, resultTemp, result, 0);   
            return result;
        }
    }
    void findIp(string & s, vector<string> & resultTemp, vector<string> & result, unsigned index) {
        if(resultTemp.size() == 4) {
            if(index == s.size()) {
                string temp;
                for(int i = 0; i < 3; ++i) {
                    temp += resultTemp[i] + ".";
                }
                temp += resultTemp[3];
                result.push_back(temp);
            }
            return;
        }
        string ipNumber;
        for(unsigned i = index; i < s.size() && i < index + 3; ++i) {
            ipNumber += s[i];
            if(valid(ipNumber)) {
                resultTemp.push_back(ipNumber);
                findIp(s, resultTemp, result, i + 1);
                resultTemp.pop_back();
            }
        }
    }
    bool valid(string s) {
        if(s.size() == 0 || s.size() > 3) {
            return false;
        }
        if(s[0] == '0' && s.size() != 1) {
            return false;
        }
        else {
            int sum = 0;
            for(int i = s.size() - 1; i >= 0; --i) {
                sum += (s[i] - '0') * pow(10, s.size() - i - 1);
            }
            if(sum > 255) return false;
        }
        return true;
    }
};

int main() {
    string s = "2525511135";

    Solution test;
    vector<string> result = test.restoreIpAddresses(s);

    for(auto c : result) {
        cout << c << endl;
    }
    return 0;
}
