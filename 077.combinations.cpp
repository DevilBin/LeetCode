/*************************************************************************
	> File Name: 077.combinations.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/2/25 10:18:40
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
    vector<vector<int> > combine(int n, int k) {
        vector<int> temp;
        vector<vector<int> > result;
        findCombine(n, 1, k, temp, result);
        return result;
    }
    void findCombine(int n, int start, int k, vector<int> & temp, vector<vector<int> > & result) {
        if(k == 0) {
            result.push_back(temp);
        } else {
            for(int i = start; i <= n - k + 1; ++i) {
                temp.push_back(i);
                findCombine(n, i + 1, k - 1, temp, result);
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution test;
    vector<vector<int> > result = test.combine(4, 2);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
};

