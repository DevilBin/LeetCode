/*************************************************************************
	> File Name: 088.mergeSortedArray.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/4 11:13:30
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
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) {
        if(m == 0) {
            nums1 = nums2;
        }
        else if(n == 0) {
            return;
        }
        else {
            vector<int> result;
            int index1 = 0;
            int index2 = 0;
            while(index1 < m && index2 < n) {
                if(nums1[index1] > nums2[index2]) {
                    result.push_back(nums2[index2]);
                    index2++;
                }
                else {
                    result.push_back(nums1[index1]);
                    index1++;
                }
            }
            while(index1 < m) {
                result.push_back(nums1[index1]);
                index1++;
            }
            while(index2 < n) {
                result.push_back(nums2[index2]);
                index2++;
            }
            nums1 = result;
        }
    }
};

int main() {
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {2};

    Solution test;
    test.merge(nums1, 1, nums2, 1);

    for(auto c : nums1) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
