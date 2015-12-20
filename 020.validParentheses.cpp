/*************************************************************************
	> File Name: 020.validParentheses.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sun 20 Dec 2015 07:31:01 PM CST
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
    bool isValid(string s) {
        if(s.size() <= 1) {
            return false;
        }
        else {
            vector<char> str;
            str.push_back(s[0]);
            for(unsigned i = 1; i < s.size(); ++i) {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    str.push_back(s[i]);
                    continue;
                }
                char c = str.back();
                if(s[i] == ')' && c != '(') {
                    return false;
                }
                if(s[i] == ']' && c != '[') {
                    return false;
                }
                if(s[i] == '}' && c != '{') {
                    return false;
                }
                str.pop_back();
            }
            if(str.size() != 0) {
                return false;
            }
            else 
                return true;
        }
    }
};

int main() {
    string s = ")}{({))[{{[}";
    Solution test;
    cout << test.isValid(s) << endl;
    return 0;
}
