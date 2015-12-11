/*************************************************************************
	> File Name: 011.containerWithMostWater.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 11 Dec 2015 06:40:27 PM CST
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
    inline int max(int x, int y) {
        if(x > y)
            return x;
        else
            return y;
    }
    inline int min(int x, int y) {
        if(x < y)
            return x;
        else
            return y;
    }
    int maxArea(vector<int> & height) {
        int retmax = 0;
        int left = 0; int right = height.size() - 1;
        while(left < right) {
            retmax = max(retmax, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return retmax;
    }
};

int main() {
    const int arr[] = {1, 4, 3, 2, 1};
    vector<int> height(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.maxArea(height) << endl;
    return 0;
}
