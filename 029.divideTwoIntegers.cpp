/*************************************************************************
	> File Name: 029.divideTwoIntegers.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sun 27 Dec 2015 05:15:59 PM CST
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
    Solution() {
        i = 0;
        sign = 1;
        result = 0;
    }
    int divide(int dividend, int divisor) {
        if(!divisor) {
            return dividend > 0 ? INT_MAX : INT_MIN;
        }
        else if(!dividend) {
            return 0;
        }
        else {
            if(dividend < 0) {
                sign *= -1;
            }
            if(divisor < 0) {
                sign *= -1;
            }
            dvd = dividend > 0 ? dividend: -dividend;
            divisor_origin = dvs = divisor < 0 ? -divisor : divisor;
            while(dvd > dvs << i) { i++; }
            while(divisor_origin <= dvd) {
                if(dvs << i <= dvd) {
                    dvd -= dvs << i;
                    result += (unsigned long) 1 << i;
                }
                i--;
            }
            if(sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            return result * sign;
        }
    }
private:
    int i;
    int sign;
    unsigned result;
    unsigned dvd;
    unsigned dvs;
    unsigned divisor_origin;
};

int main() {
    int dividend = -2147483648;
    int divisor = -1;

    Solution test;
    cout << test.divide(dividend, divisor) << endl;
    return 0;
}
