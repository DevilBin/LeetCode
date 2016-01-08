/*************************************************************************
	> File Name: 049.groupAnagrams.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 08 Jan 2016 05:42:24 PM CST
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
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> & strs) {
        vector<vector<string> > result;
        if(strs.size() == 0) {
            return result;
        }
        else {
            unordered_map<string, vector<int> > maps;
            for(unsigned i = 0; i < strs.size(); ++i) {
                string key = strs[i];
                sort(key.begin(), key.end());
                maps[key].push_back(i);
            }
            for(auto it = maps.begin(); it != maps.end(); ++it) {
                vector<string> capacity;
                if(it->second.size() > 0) {
                    unsigned n = 0;
                    while(n < it->second.size()) {
                        capacity.push_back(strs[it->second[n]]);
                        n++;
                    }
                    sort(capacity.begin(), capacity.end());
                    result.push_back(capacity);
                }
            }
            return result;
        }
    }
};

int main() {
    const string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs; 
    Solution test;

    for(unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        strs.push_back(arr[i]);
    }
    vector<vector<string> > result = test.groupAnagrams(strs);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
