/*************************************************************************
	> File Name: 089.grayCode.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/5 13:15:45
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
    vector<int> grayCode(int n) {
        vector<int> numb_result;
        vector<string> result = {"0", "1"};
        if(n == 0) {
            numb_result.push_back(0);
            return numb_result;
        }
        else {
            func(n, result);
            for(auto c : result) {
                numb_result.push_back(change(c));
            }
            return numb_result;
        }
    }
    void func(int n, vector<string> & result) {
        if(n == 1) {
            return;
        }
        else {
            vector<string> temp = result;
            int temp_size = temp.size();
            int temp_last_size = temp[temp_size - 1].size();
            for(int i = temp_size - 1; i >= 0; --i) {
                int j = 0;
                int k = temp[i].size();
                string binNumber = temp[i];       
                while(j + k < temp_last_size) {
                    binNumber += "0";
                    j++;
                }
                binNumber += "1";
                result.push_back(binNumber);
            }
            func(n - 1, result);
        }
    }
    int change(string str) {
        int sum = 0;
        for(int i = 0; i < static_cast<int>(str.size()); ++i) {
            sum += (str[i] - '0') * pow(2, i);
        }
        return sum;
    }
};

int main() {
    Solution test;
    vector<int> result = test.grayCode(7);

    for(auto c : result) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
