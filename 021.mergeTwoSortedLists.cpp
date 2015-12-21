/*************************************************************************
	> File Name: 021.mergeTwoSortedLists.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/21 13:43:58
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

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if(l1 == NULL) {
            return l2;
        }
        else if(l2 == NULL) {
            return l1;
        }
        else {
            ListNode result(0);
            ListNode * current = new ListNode(0);
            result.next = current;
            while(l1 != NULL && l2 != NULL) {
                if(l1->val > l2->val) {
                    current->next = l2;
                    l2 = l2->next;
                }
                else {
                    current->next = l1;
                    l1 = l1->next;
                }
                current = current->next;
            }
            if(l1 == NULL) {
                current->next = l2;
            }
            if(l2 == NULL) {
                current->next = l1;
            }
            return result.next->next;            
        }
    }
};

int main() {
    const int n1[] = {2, 3, 5, 6, 9, 13, 15, 17};
    const int n2[] = {1, 2, 4, 7, 8, 12};
    ListNode l1(0); ListNode l2(0);
    ListNode * p1 = &l1; ListNode * p2 = &l2;

    for(unsigned i = 0; i < sizeof(n1) / sizeof(n1[0]); ++i) {
        ListNode * p1Node = new ListNode(n1[i]);
        p1->next = p1Node;
        p1 = p1->next;
    }
    for(unsigned i = 0; i < sizeof(n2) / sizeof(n2[0]); ++i) {
        ListNode * p2Node = new ListNode(n2[i]);
        p2->next = p2Node;
        p2 = p2->next;
    }

    Solution test;
    p1 = test.mergeTwoLists(l1.next, l2.next);
    while(p1) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    cout << endl;

    return 0;
}
