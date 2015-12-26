/*************************************************************************
	> File Name: 028.implementstrStr.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sat 26 Dec 2015 02:17:43 PM CST
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
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        else if(haystack.size() == 0 && needle.size() != 0) {
            return -1;
        }
        else {
            return kmp_search(haystack, needle);
        }
    }
    vector<int> kmp_table(string needle) {
        vector<int> result;
        if(needle.size() == 0) {
            return result;
        }
        else if(needle.size() == 1) {
            result.push_back(-1);
            return result;
        }
        else if(needle.size() == 2) {
            result.push_back(-1);
            result.push_back(0);
            return result;
        }
        else {
            result.push_back(-1);
            result.push_back(0);
            unsigned pos = 2; unsigned cnd = 0;
            while(pos < needle.size()) {
                if(needle[pos - 1] == needle[cnd]) {
                    result.push_back(cnd + 1);
                    cnd++; pos++;
                }
                else if(cnd > 0) {
                    cnd = result[cnd];
                }
                else {
                    result.push_back(0);
                    pos++;
                }
            }
            return result;
        }
    }
    int kmp_search(string haystack, string needle) {
        vector<int> table = kmp_table(needle);
        unsigned m = 0; unsigned i = 0;
        while(m + i < haystack.size()) {
            if(needle[i] == haystack[m + i]) {
                if(i == needle.size() - 1) {
                    return m;
                }
                i++;
            }
            else {
                if(table[i] > -1) {
                    m = m + i - table[i];
                    i = table[i];
                }
                else {
                    i = 0;
                    m = m + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "ABC ABCDAB ABCDABCDABDE";
    string needle = "ABCDABD";

    Solution test;
    int ret = test.strStr(haystack, needle);
    cout << ret << endl;
    return 0;
}
