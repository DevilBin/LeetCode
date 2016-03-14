/*************************************************************************
	> File Name: 101.symmetricTree.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/14 21:51:37
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
    bool isSymmetric(TreeNode * root) {
        if(root == NULL) {
            return true;
        }
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode * p, TreeNode * q) {
        if(p == NULL || q == NULL) {
            if(p == q)
                return true;
            else
                return false;
        }
        if(p->val == q->val && isEqual(p->left, q->right) && isEqual(p->right, q->left))
            return true;
        else
            return false;
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
    const int arr[] = {1, 2};
    TreeNode * root = new TreeNode(arr[0]);
    deque<TreeNode *> nodes = {root};

    init(nodes, arr, sizeof(arr) / sizeof(arr[0]));

    Solution test;
    cout << test.isSymmetric(root) << endl;
    return 0;
}
