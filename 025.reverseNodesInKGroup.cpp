/*************************************************************************
    > File Name: 025.reverseNodesInKGroup.cpp
    > Author: DevilBin
    > Mail: whu.evil.binary@gmail.com
    > Created Time: Sun 27 Nov 2016 07:29:43 PM CST
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

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode * reverseKGroup(ListNode * head, int k) {
        ListNode l(0);
        ListNode * root     = &l;
        ListNode * later    = head;
        vector<int> compacity(k, 0);
        if(k <= 0)
            return head;
        while(later != NULL) {
            int index = k;
            while(later != NULL && index) {
                compacity[--index] = later->val;
                later = later->next;
            }
            if(index == 0) {
                for(size_t i = 0; i < compacity.size(); ++i) {
                    root->next = new ListNode(compacity[i]);
                    root = root->next;
                }
            }
            else {
                for(int i = k - 1; i >= index; --i) {
                    root->next = new ListNode(compacity[i]);
                    root = root->next;
                }
            }
        }
        return l.next;
    }
};

int main() {
    ListNode l(0);
    ListNode * head = &l;
    for(int index = 0; index < 10; ++index) {
        head->next = new ListNode(index);
        head = head->next;
    }
    Solution test;
    head = test.reverseKGroup(l.next, 3);
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
