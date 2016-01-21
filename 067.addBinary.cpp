/*************************************************************************
	> File Name: 067.addBinary.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/20 13:20:12
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
    string addBinary(string a, string b) {
        if(a.size() == 0) {
            return b;
        }
        else if(b.size() == 0) {
            return a;
        }
        else {
            int c = 0;
            string result;
            unsigned index = 0;
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            while(index < a.size() && index < b.size()) {
                int sum = a[index] - '0' + b[index] - '0' + c;
                if(sum > 1) {
                    c = sum / 2;
                    result += sum % 2 + '0';
                }
                else {
                    c = 0;
                    result += sum + '0';
                }
                index++;
            }
            while(index < a.size()) {
                int sum = a[index] - '0' + c;
                if(sum > 1) {
                    c = sum / 2;
                    result += sum % 2 + '0';
                }
                else {
                    c = 0;
                    result += sum + '0';
                }
                index++;
            }
            while(index < b.size()) {
                int sum = b[index] - '0' + c;
                if(sum > 1) {
                    c = sum / 2;
                    result += sum % 2 + '0';
                }
                else {
                    c = 0;
                    result += sum + '0';
                }
                index++;
            }
            if(c > 0) {
                result += '1';
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }
};

int main() {
    Solution test;
    cout << test.addBinary("1", "111") << endl;
    return 0;
}
