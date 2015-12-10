/*************************************************************************
	> File Name: 009.palindromeNumber.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Thu 10 Dec 2015 04:51:35 PM CST
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
    inline string strReverse(string str) {
        int i, j;
        for(j = 0, i = str.size() - 1; j < i; --i, ++j) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }
    bool isPalindrome(int x) {
        if(x >= 0 && x < INT_MAX) {
            s << x;
            string str = s.str();
            if(str == strReverse(str))
                return true;
            else
                return false;
        }
        else {
            return false;
        }
    }
private:
    char temp;
    stringstream s;
};

int main() {
    int x = -2147447412;
    Solution test;
    cout << test.isPalindrome(x) << endl;
}
