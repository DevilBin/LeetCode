/*************************************************************************
	> File Name: 043.multiplyStrings.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Mon 04 Jan 2016 10:35:27 AM CST
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
        sign = 0;
        index = 0;
        processNum = 0;
    }
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) {
            return 0;
        }
        else {
            string result(num1.size() + num2.size() + 1, '0');
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            for(unsigned j = 0; j < num2.size(); ++j) {
                temp_index = index;
                for(unsigned i = 0; i < num1.size(); ++i) {
                    processNum = sign + result[temp_index] - '0' + (num1[i] - '0') * (num2[j] - '0');
                    result[temp_index] = (char)(processNum % 10 + '0');
                    sign = processNum / 10;
                    temp_index++;
                }
                if(sign) {
                    result[temp_index] = (char)(sign + '0');
                    sign = 0;
                }
                index++;
            }
            k = result.size() - 1;
            while(k > 0 && result[k] == '0') {
                k--;
            }
            result.resize(k + 1);
            reverse(result.begin(), result.end());
            return result;
        }
    }
private:
    int k;
    int sign;
    int index;
    int temp_index;
    int processNum;
};

int main() {
    string num1 = "39";
    string num2 = "29";

    Solution test;
    cout << test.multiply(num1, num2) << endl;
    return 0;
}
