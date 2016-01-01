/*************************************************************************
	> File Name: 038.countAndSay.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 01 Jan 2016 12:07:38 PM CST
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
    string countAndSay(int n) {
        string result = "1";
        if(n == 1) {
            return "1";
        }
        else if(n == 2) {
            return "11";
        }
        else {
            n = n - 2;
            while(n >= 0) {
                result = generate(result);
                n--;
            }
            return result;
        }
    }
    string generate(string & str) {
        string capacity;
        for(unsigned i = 0; i < str.size(); ++i) {
            unsigned j, k;
            stringstream ss;
            j = k = i;
            while(j < str.size() && str[j] == str[j + 1]) {
                j++;
                i++;
            }
            ss << j - k + 1;
            capacity += ss.str() + str[j];
        }
        return capacity;
    }
};

int main() {
    Solution test;
    cout << test.countAndSay(7) << endl;
    return 0;
}
