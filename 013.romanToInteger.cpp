/*************************************************************************
	> File Name: 013.romanToInteger.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sun 13 Dec 2015 07:05:25 PM CST
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
    int romanToInt(string s) {
        int m = 0; int n = 0; int sum = 0;
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        if(s.size() == 0)
            return 0;
        else {
            for(int i = 0; m < static_cast<int>(s.size()); ++i) {
                while(s.compare(m, symbol[n].size(), symbol[n]) == 0) {
                    m = m + symbol[n].size();
                    sum = sum + number[n];
                }
                n++;
            }
            return sum;
        }
    }
};

int main() {
    string s = "MMDLXIII";
    Solution test;
    cout << test.romanToInt(s) << endl;
    return 0;
}
