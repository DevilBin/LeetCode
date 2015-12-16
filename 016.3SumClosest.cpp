/*************************************************************************
	> File Name: 016.3SumClosest.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Wed 16 Dec 2015 04:59:44 PM CST
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
    int threeSumClosest(vector<int> & nums, int target) {
        int min = INT_MAX;
        int result = 0;
        if(nums.size() < 3) {
            return 0;
        }
        else {
            QuickSort(nums, 0, nums.size() - 1);
            for(unsigned i = 0; i < nums.size(); ++i) {
                int start = i + 1;
                int end = nums.size() - 1;
                while(start < end) {
                    int sum = nums[i] + nums[start] + nums[end];
                    int diff = abs(sum - target);
                    if(diff == 0) {
                        return sum;
                    }
                    if(diff < min) {
                        min = diff;
                        result = sum;
                    }
                    if(sum <= target) {
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
            return result;
        }
    }
    int Split(vector<int> & A, int low, int high) {
        int i = low; int x = A[low];
        for(int j = low + 1; j <= high; ++j) {
            if(A[j] <= x) {
                i = i + 1;
                if(i != j) {
                    Swap(A[i], A[j]);
                }
            }
        }
        Swap(A[i], A[low]);
        return i;
    }
    void QuickSort(vector<int> & A, int low, int high) {
        if(low < high) {
            int w = Split(A, low, high);
            QuickSort(A, low, w - 1);
            QuickSort(A, w + 1, high);
        }
    }
    void Swap(int & x, int & y) {
        int z;
        z = x;
        x = y;
        y = z; 
    }
};

int main() {
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.threeSumClosest(nums, 1) << endl;
    return 0;
}
