/*************************************************************************
	> File Name: 100.sameTree.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/13 21:47:35
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
    bool isSameTree(TreeNode * p, TreeNode * q) {
        return isEqual(p, q);
    }
    bool isEqual(TreeNode * p, TreeNode * q) {
        if(p == NULL || p == NULL) {
            if(p == q)
                return true;
            else
                return false;
        }
        if(p->val == q->val && isEqual(p->left, q->left) && isEqual(p->right, q->right))
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

void print(TreeNode * root) {
    cout << root->val << ' ';
    deque<TreeNode *> nodes = {root};
    while(nodes.size() != 0) {
        TreeNode * head = nodes[0];
        if(head->left != NULL) {
            cout << head->left->val << ' ';
            nodes.push_back(head->left);
        }
        else {
            cout << "#" << ' ';
        }
        if(head->right != NULL) {
            cout << head->right->val << ' ';
            nodes.push_back(head->right);
        }
        else {
            cout << "#" << ' ';
        }
        nodes.pop_front();
    }
}

int main() {
    const int arr0[] = {1, 2, 3, '#', '#', 4, '#', '#', 4};
    const int arr1[] = {1, 2, 3, '#', '#', 4, '#', '#', 5};
    TreeNode * root0 = new TreeNode(arr0[0]);
    TreeNode * root1 = new TreeNode(arr1[0]);
    deque<TreeNode *> nodes0 = {root0};
    deque<TreeNode *> nodes1 = {root1};

    init(nodes0, arr0, sizeof(arr0) / sizeof(arr0[0]));
    init(nodes1, arr1, sizeof(arr1) / sizeof(arr1[0]));

    Solution test;
    cout << test.isSameTree(root0, root1) << endl;
    return 0;
}
