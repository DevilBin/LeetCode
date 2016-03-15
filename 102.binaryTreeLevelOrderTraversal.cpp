/*************************************************************************
	> File Name: 102.binaryTreeLevelOrderTraversal.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/15 22:32:43
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
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if(root == NULL) {
            return result;
        }
        change(root, result);
        return result;
    }
    void change(TreeNode * root, vector<vector<int>> & result) {
        vector<int> intTemp = {root->val};
        result.push_back(intTemp);
        deque<TreeNode *> nodesTemp;
        deque<deque<TreeNode *>> nodes = {{root}};
        intTemp = {};
        while(nodes.size() != 0 && nodes[0].size() != 0) {
            TreeNode * head = nodes[0][0];
            if(head->left != NULL) {
                intTemp.push_back(head->left->val);
                nodesTemp.push_back(head->left);
            }
            if(head->right != NULL) {
                intTemp.push_back(head->right->val);
                nodesTemp.push_back(head->right);
            }
            if(nodes[0].size() > 1) {
                nodes[0].pop_front();
            }
            else {
                if(intTemp.size() != 0) {
                    result.push_back(intTemp);
                    intTemp = {};
                }
                nodes.push_back(nodesTemp);
                nodes.pop_front();
                nodesTemp = {};
            }
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
    vector<vector<int>> result = test.levelOrder(root);

    for(unsigned i = 0; i < result.size(); ++i) {
        for(unsigned j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
