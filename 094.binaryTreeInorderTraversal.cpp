/*************************************************************************
	> File Name: 094.binaryTreeInorderTraversal.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/10 11:16:55
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
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        print(root, result);
        return result;
    }
    void print(TreeNode * root, vector<int> & result) {
        if(root == NULL) {
            return;
        }
        print(root->left, result);
        result.push_back(root->val);
        print(root->right, result);
    }
};

void init(deque<TreeNode *> & nodes, const int arr[], int size) {
    int i = 1;
    while(i < size) {
        if(arr[i] != '#' && i < size) {
            nodes[0]->left = new TreeNode(arr[i]);
            nodes.push_back(nodes[0]->left);
        }
        i++;
        if(arr[i] != '#' && i < size) {
            nodes[0]->right = new TreeNode(arr[i]);
            nodes.push_back(nodes[0]->right);
        }
        i++;
        nodes.pop_front();
    }
}

int main() {
    const int arr[] = {1, 2, 3, '#', '#', 4, '#', '#', 5};
    TreeNode * root = new TreeNode(arr[0]);
    deque<TreeNode *> nodes = {root};

    init(nodes, arr, sizeof(arr) / sizeof(arr[0]));

    Solution test;
    vector<int> result = test.inorderTraversal(root);

    for(auto c : result) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
