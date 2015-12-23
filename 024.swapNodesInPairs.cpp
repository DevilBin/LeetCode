/*************************************************************************
	> File Name: 024.swapNodesInPairs.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Wed 23 Dec 2015 06:34:37 PM CST
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
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode * swapPairs(ListNode * head) {
        ListNode result(0);
        if(!head) {
            return result.next; 
        }
        else if(!head->next) {
            return head;
        }
        else {
            result.next = head->next;
            ListNode * p1 = head;
            ListNode * p2 = head->next;
            while(p2) {
                ListNode * p3 = NULL;
                ListNode * p4 = NULL;
                if(p2->next) {
                    p3 = p2->next;
                    if(p3->next) {
                        p4 = p3->next;
                    }
                    else {
                        p4 = NULL;
                    }
                }
                else {
                    p3 = NULL;
                }
                if(p4) {
                    p1->next = p4;
                }
                else {
                    p1->next = p3;
                }
                p2->next = p1;
                p1 = p3;
                p2 = p4; 
            }
            return result.next;
        }
    }
};

int main() {
    const int n1[] = {1, 2, 3, 4};
    ListNode l1(0);
    ListNode * p1 = &l1;

    for(unsigned i = 0; i < sizeof(n1) / sizeof(n1[0]); ++i) {
        ListNode * p1Node = new ListNode(n1[i]);
        p1->next = p1Node;
        p1 = p1->next;
    }

    Solution test;
    p1 = test.swapPairs(l1.next);
    while(p1) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    cout << endl;

    return 0;
}
