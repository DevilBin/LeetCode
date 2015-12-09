/*************************************************************************
	> File Name: 007.reverseInteger.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Wed 09 Dec 2015 02:38:18 PM CST
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
    inline void strReverse(string & str) {
        size_t i, j;
        for(j = 0, i = str.size() - 1; j < i; --i, ++j) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    int reverse(int x) {
        if(x == 0)
            return 0;
        else if(x < 0) {
            xtemp = -x;
            s << xtemp;
            string str = s.str();
            strReverse(str);
            if(atol(str.c_str()) > INT_MAX) {
                return 0;
            }
            else {
                return -atol(str.c_str());
            }
        }
        else {
            s << x;
            string str = s.str();
            strReverse(str);
            if(atol(str.c_str()) > INT_MAX) {
                return 0;
            }
            else {
                return atol(str.c_str());
            }
        }
    }
private:
    char temp;
    long int xtemp;
    stringstream s;
    stringstream intMax;
    stringstream intMin;
};

int main() {
    int x = -2147483641;
    Solution test;
    cout << test.reverse(x) << endl;
    return 0;
}
