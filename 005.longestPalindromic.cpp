/*************************************************************************
	> File Name: 005.longestPalindromic.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Mon 07 Dec 2015 02:21:09 PM CST
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

using namespace std;

class Solution {
public:
    Solution() {
        start = 0;
        maxlen = 0;
    }
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        else if(s.length() == 1)
            return s;
        else {
            for(int i = 1; i < static_cast<int>(s.length()); ++i) {
                int low = i - 1; int high = i;
                while(low >= 0 && high < static_cast<int>(s.length()) && s[low] == s[high]) {
                    low--;
                    high++;
                }
                if(high - low - 1 > maxlen) {
                    maxlen = high -low - 1;
                    start = low + 1;
                }
                low = i; high = i;
                while(low >= 0 && high < static_cast<int>(s.length()) && s[low] == s[high]) {
                    low--;
                    high++;
                }
                if(high - low - 1 > maxlen) {
                    maxlen = high -low - 1;
                    start = low + 1;
                }
            }
            return s.substr(start, maxlen);
        }
    }
private:
    int start;
    int maxlen;
};

int main() {
    string s = "aaa";
    Solution test;
    string stemp = test.longestPalindrome(s);
    cout << stemp;
    return 0;
}
