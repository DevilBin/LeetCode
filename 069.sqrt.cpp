/*************************************************************************
	> File Name: 069.sqrt.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/22 11:58:26
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
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        else if(x >0 && x < 4) {
            return 1;
        }
        else {
            int start = 0;
            int end = x;
            while(start <= end) {
                int mid = start + (end - start) / 2;
                if(mid == x / mid) {
                    return mid;
                }
                else if(mid > x / mid) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            return end;
        }
    }
};

int main() {
    Solution test;
    cout << test.mySqrt(9999999) << endl;
    return 0;
}
