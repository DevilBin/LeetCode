/*************************************************************************
	> File Name: 003.longestSubstring.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sun 06 Dec 2015 08:53:38 PM CST
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
        maxlen = 1;
        last_start = 0;
        index = 1;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        else {
            for(int i = 1; i < static_cast<int>(s.length()); ++i) {
                for(int j = i - 1; j >= last_start; --j) {
                    if(s[i] == s[j]) {
                        index = i - j;
                        last_start = j + 1;
                        break;
                    }
                    else if(j == last_start) {
                        index++;
                    }
                }
                if(index > maxlen) {
                    maxlen = index;
                }
            }
        }
        return maxlen;
    }
private:
    int index;
    int last_start;
    int maxlen;
};

int main() {
    string s = "abceeefadc";
    Solution test;
    int len = test.lengthOfLongestSubstring(s);
    cout << len << endl;
    return 0;
}
