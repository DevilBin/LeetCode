/*************************************************************************
	> File Name: 006.zigZag.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 08 Dec 2015 06:39:57 PM CST
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
    string convert(string s, int numRows) {
        string stemp;
        int len = static_cast<int>(s.length());

        if(len == 0)
            return "";
        else if(len == 1 || numRows == 1)
            return s;
        else {
            int i_row = numRows - 1;
            int j_line = (len - 1) / (2 * i_row);

            for(int i = 0; i <= i_row; ++i) {
                for(int j = 0; j <= j_line; ++j) {
                    int index0 = 2 * i_row * j + i;
                    int index1 = 2 * i_row * (j + 1) - i;

                    if((i == 0 || i == i_row) && index0 < len) {
                        stemp.append(1, s[index0]);
                    }
                    else {
                        if(index0 < len) {
                            stemp.append(1, s[index0]);
                        }
                        if(index1 < len) {
                            stemp.append(1, s[index1]);
                        }
                    }
                }
            }
            return stemp;
        }
    }
};

int main() {
    string s = "AB";
    Solution test;
    string stemp = test.convert(s, 3);
    cout << stemp;
    return 0;
}
