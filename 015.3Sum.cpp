/*************************************************************************
	> File Name: 015.3Sum.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Tue 15 Dec 2015 07:23:36 PM CST
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
    vector<vector<int> > threeSum(vector<int> & nums) {
        int a, b, c;
        int start, end;
        vector<vector<int> > result;
        if(nums.size() < 3) {
            return result;
        }
        else {
            QuickSort(nums, 0, nums.size() - 1);
            for(unsigned i = 0; i < nums.size() - 2; ++i) {
                if(i == 0 || nums[i] > nums[i - 1]) {
                    a = nums[i];
                    start = i + 1;
                    end = nums.size() - 1;
                    while(start < end) {
                        b = nums[start];
                        c = nums[end];
                        if(a + b + c == 0) {
                            vector<int> row;
                            row.push_back(a);
                            row.push_back(b);
                            row.push_back(c);
                            result.push_back(row);
                            start = start + 1;
                            end = end - 1;
                            while(start < end && nums[end] == nums[end + 1]) {
                                end--;
                            }
                            while(start < end && nums[start] == nums[start - 1]) {
                                start++;
                            }
                        }
                        else if(a + b + c > 0) {
                            end = end - 1;
                        }
                        else {
                            start = start + 1;
                        }
                    }
                }
            }
        }
        return result;
    }
    int Split(vector<int> & A, int low, int high) {
        int temp; int i = low; int x = A[low];
        for(int j = low + 1; j <= high; ++j) {
            if(A[j] <= x) {
                i = i + 1;
                if(i != j) {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
        temp = A[low];
        A[low] = A[i];
        A[i] = temp;
        return i;
    }
    void QuickSort(vector<int> & A, int low, int high) {
        if(low < high) {
            int w = Split(A, low, high);
            QuickSort(A, low, w - 1);
            QuickSort(A, w + 1, high);
        }
    }
};

int main() {
    vector<vector<int> > :: const_iterator row;
    vector<int> :: const_iterator col;
    int arr[] = {-1, 0, 1};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<vector<int> > result = test.threeSum(nums);
    for(row = result.begin(); row != result.end(); ++row) {
        for(col = row->begin(); col != row->end(); ++col) {
            cout << *col << ' ';
        }
        cout << '\n';
    }
    return 0;
}
