/*************************************************************************
	> File Name: 039.combinationSum.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sat 02 Jan 2016 01:41:56 PM CST
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
    vector<vector<int> > combinationSum(vector<int> & candidates, int target) {
        if(candidates.size() == 0) {
            return result;
        }
        else {
            sort(candidates.begin(), candidates.end());
            handler(candidates, capacity, 0, target);
            return result;
        }
    }

    void handler(vector<int> & candidates, vector<int> & capacity, int index, int target) {
        if(target == 0) {
            result.push_back(capacity);
            return;
        }
        unsigned i = index;
        while(i < candidates.size() && target >= candidates[index]) {
            if(i == 0 || candidates[index] != candidates[index - 1]) {
                capacity.push_back(candidates[i]);
                handler(candidates, capacity, i, target - candidates[i]);
                capacity.pop_back();
            }
            i++;
        }
    }
private:
    vector<int> capacity;
    vector<vector<int> > result;
};

int main() {
    const int arr[] = {2, 3, 4};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<vector<int> > result = test.combinationSum(candidates, 7);
    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
