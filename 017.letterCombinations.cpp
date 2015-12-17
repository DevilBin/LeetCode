/*************************************************************************
	> File Name: 017.letterCombinations.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Thu 17 Dec 2015 01:53:49 PM CST
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
    vector<string> letterCombinations(string digits) {
        string symbol[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //0: space, 1: NULL, 2: "abc", 3: "def"...
        vector<string> empty;
        if(digits.size() == 0) {
            return empty;
        }
        else {
            vector<string> result(1, "");//at first, reslut is NULL
            for(unsigned i = 0; i < digits.size(); ++i) {
                vector<string> capacity;
                for(unsigned j = 0; j < result.size(); ++j) {
                    for(unsigned k = 0; k < symbol[digits[i] - '0'].size(); ++k) {
                        capacity.push_back(result[j] + symbol[digits[i] - '0'][k]);
                    }
                }
                result = capacity;
            }
            return result;
        }
    }
};

int main() {
    string str = "243";
    Solution test;
    vector<string> strvec = test.letterCombinations(str);

    for(unsigned i = 0; i < strvec.size(); ++i) {
        cout << strvec[i] << " ";
    }
    return 0;
}
