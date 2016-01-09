/*************************************************************************
	> File Name: 050.pow.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/9 13:06:52
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
    double myPow(double x, int n) {
        if(n > 0) {
            return power(x, n);
        }
        else {
            return 1.0 / power(x, -n);
        }
    }

    double power(double x, int n) {
        double y;
        if(n == 0)
            return 1.0;
        y = power(x, n / 2);
        if(n % 2 == 0) 
            return y * y;
        else
            return y * y * x;
    }
};

int main() {
    Solution test;
    cout << test.myPow(0.00001, 2147483647) << endl;
    return 0;
}
