/*************************************************************************
	> File Name: 071.simplifyPath.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/21 17:15:20
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
#include <assert.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        string simplyString;
        vector<string> result;
        vector<string> resultTemp;
        assert(path[0] == '/');
        for(unsigned i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(temp.size()) {
                    resultTemp.push_back(temp);
                    temp.resize(0);
                }
            }
            else {
                temp += path[i];
            }
        }
        if(temp.size()) {
            resultTemp.push_back(temp);
            temp.resize(0);
        }
        for(unsigned i = 0; i < resultTemp.size(); ++i) {
            if(resultTemp[i] == ".") {
                continue;
            }
            else if(resultTemp[i] == "..") {
                if(result.size() > 0) {
                    result.pop_back();
                }
            }
            else {
                result.push_back(resultTemp[i]);
            }
        }
        if(result.size()) {
            for(unsigned i = 0; i < result.size(); ++i) {
                simplyString += '/';
                simplyString += result[i];
            }
        }
        else {
            simplyString += '/';
        }
        return simplyString; 
    }
};

int main() {
    string path = "/../../a/b";
    Solution test;
    cout << test.simplifyPath(path) << endl;
    return 0;
}
