/*************************************************************************
	> File Name: 018.4Sum.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Fri 18 Dec 2015 06:23:11 PM CST
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
    vector<vector<int> > fourSum(vector<int> & nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) {
            return result;
        }
        else {
            int start, end;
            int a, b, c, d;
            QuickSort(nums, 0, nums.size() - 1);
            for(unsigned i = 0; i < nums.size() - 3; ++i) {
                if(i == 0 || nums[i] > nums[i - 1]) {
                    for(unsigned j = i + 1; j < nums.size() - 2; ++j) {
                        if(j == i + 1 || nums[j] > nums[j - 1]) {
                            a = nums[i];
                            b = nums[j];
                            start = j + 1;
                            end = nums.size() - 1;
                            while(start < end) {
                                c = nums[start];
                                d = nums[end];
                                if(a + b + c + d == target) {
                                    vector<int> row;
                                    row.push_back(a); 
                                    row.push_back(b);
                                    row.push_back(c);
                                    row.push_back(d);
                                    result.push_back(row);
                                    start++; end--;
                                    while(start < end && nums[end] == nums[end + 1]) {
                                        end--;
                                    }
                                    while(start < end && nums[start] == nums[start - 1]) {
                                        start++;
                                    }
                                }
                                else if(a + b + c + d > target) {
                                    end--;
                                }
                                else {
                                    start++;
                                }
                            }
                        }
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
    vector<vector<int> > :: const_iterator row;
    vector<int> :: const_iterator col;
    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<vector<int> > result = test.fourSum(nums, 0);
    for(row = result.begin(); row != result.end(); ++row) {
        for(col = row->begin(); col != row->end(); ++col) {
            cout << *col << ' ';
        }
        cout << '\n';
    }
    return 0;
}

