/*************************************************************************
	> File Name: 070.climbingStairs.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/27 15:13:30
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
    int climbStairs(int n) {
        if(n == 0) 
            return 0;
        else 
            return fib(n);
    }
    int fib(int x) {
        m = 1; n = 1;
        for(int i = 1; i < x; ++i) {
            k = m + n;
            m = n; 
            n = k;
        }
        return n;
    }
private:
    int m, n, k;
};

int main() {
    Solution test;
    for(int i = 0; i < 10; ++i) {
        cout << test.climbStairs(i) << endl;
    }
    return 0;
}
