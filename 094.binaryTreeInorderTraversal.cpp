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


int main() {
    TreeNode pNode(1);
    pNode.right = new TreeNode(2);
    pNode.right->left = new TreeNode(3);

    Solution test;
    vector<int> result = test.inorderTraversal(&pNode);

    for(auto c : result) {
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}
