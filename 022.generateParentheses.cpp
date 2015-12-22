/*************************************************************************
	> File Name: 022.generateParentheses.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 22 Dec 2015 04:53:42 PM CST
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
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> result;
        if(n == 0) {
            return result;
        }
        else {
            setN(n);
            combine(result, str, 0, 0, 0);
            return result;
        }
    }

    void combine(vector<string> & result, string & str,int deep, int left, int right) {
        if(deep == 2 * n) {
            result.push_back(str);
            return;
        }
        if(left < n) {
            str += '(';
            combine(result, str, deep + 1, left + 1, right);
            str.resize(str.size() - 1); // The left is end, so back to last step.
        }
        if(left > right) {
            str += ')';
            combine(result, str, deep + 1, left, right + 1);
            str.resize(str.size() - 1); // The right is end, so back to last step.
        }
    }

    void setN(int n) {
        this->n = n;
    }
private:
    int n;
};

int main() {
    vector<string> str;
    Solution test;
    str = test.generateParenthesis(3);

    for(unsigned i = 0; i < str.size(); ++i) {
        cout << str[i] << endl;
    }
    return 0;
}
