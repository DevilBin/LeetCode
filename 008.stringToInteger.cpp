/*************************************************************************
	> File Name: 008.stringToInteger.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Thu 10 Dec 2015 01:00:38 PM CST
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
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str == "")
            return 0;
        else {
            if(atol(str.c_str()) > INT_MAX) {
                return INT_MAX;
            }
            else if(atol(str.c_str()) < INT_MIN) {
                return INT_MIN;
            }
            else {
                return atol(str.c_str());
            }
        }
    }
};

int main() {
    string s = "  +0012a43";
    Solution test;
    cout << test.myAtoi(s) << endl;
    return 0;
}

