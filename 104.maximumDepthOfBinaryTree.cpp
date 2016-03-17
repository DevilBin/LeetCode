/*************************************************************************
	> File Name: 104.maximumDepthOfBinaryTree.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/17 16:00:39
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

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode * root) {
        if(root == NULL) {
            return 0;
        }
        return findMaxDepth(root, 0);
    }

    int findMaxDepth(TreeNode * root, int k) {
        if(root == NULL) {
            return k;
        }
        else {
            int m = findMaxDepth(root->left, k + 1);
            int n = findMaxDepth(root->right, k + 1);
            return m > n ? m : n;
        }
    }
};

void init(deque<TreeNode *> & nodes, const int arr[], int size) {
    int i = 1;
    while(i < size) {
        if(arr[i] != '#') {
            nodes[0]->left = new TreeNode(arr[i]);
            nodes.push_back(nodes[0]->left);
        }
        i++;
        if(arr[i] != '#') {
            nodes[0]->right = new TreeNode(arr[i]);
            nodes.push_back(nodes[0]->right);
        }
        i++;
        nodes.pop_front();
    }
}

int main() {
    const int arr[] = {3, 9, 20, '#', '#', 15, 7};
    TreeNode * root = new TreeNode(arr[0]);
    deque<TreeNode *> nodes = {root};

    init(nodes, arr, sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.maxDepth(root) << endl;
    return 0;
}
