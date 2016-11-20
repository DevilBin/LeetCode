/*************************************************************************
	> File Name: 010.regularExpressionMatching.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sun 20 Nov 2016 10:55:51 AM CST
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
    bool isMatch(string s, string p) {
        /*
         *  If p is empty, return value is result of whether s is empty.
         */
        if(p.empty()) return s.empty();
        /*
         *  There is only two condition, the first '*' is equal to p[1], the second '*' isn't equal to p[1].
         *  When '*' equal to p[1], the '*' can replace p[0] zero times or more times. So considering zero time,
         *  s should match with p[2]... ie isMatch(s, p.substr(2)) return true. On the other hand, '*'replace 
         *  p[0] once or more. If '*' take the place of p[0] once, the s can't be empty, or will return false, 
         *  and s[0] should equal to p[0], still has another situation, the p[0] is '.'; and s[1] to the end 
         *  should equal to p[2]...('*' repalce once), or p[0]...('*' replace more the once), it's hard to 
         *  understand, but the long match is better the short, or you should wirte isMatch(s.substr(1),
         *  p.substr(2)) || is.Match(s.substr(1), p))). But more time using, when p is equal to s[1].., contains
         *  of the situation p[2]... is equal to s[1]...
         */
        /*
         *  When '*' is not equal to p[1], the situation is much more simplify. S can't be empty, and s[0] equal
         *  to p[1], or '.' is equal to p[1], and s[1]... is equal to p[1]...
         */
        if('*' == p[1])
            return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
        else
            return (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1)));
    }
};

int main() {
    Solution test;
    cout << test.isMatch("aab", "c*a*b");
    return 0;
}
