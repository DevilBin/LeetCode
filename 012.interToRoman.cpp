/*************************************************************************
	> File Name: 012.interToRoman.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/12 14:50:15
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
    string intToRoman(int num) {
        int n = 0;
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        if(num < 0 || num > 3999) {
            return "";
        }
        else {
            for(int i = 0; num != 0; ++i) {
                while(num >= number[n]) {
                    str.append(symbol[n]);
                    num = num - number[n];
                }
                n++;
            }
            return str;
        }
    }
private:
    string str;
};

int main() {
    int num = 102;
    Solution test;
    cout << test.intToRoman(num) << endl;
    return 0;
}
