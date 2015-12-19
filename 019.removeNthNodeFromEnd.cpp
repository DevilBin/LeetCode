/*************************************************************************
	> File Name: 019.removeNthNodeFromEnd.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: Sat 19 Dec 2015 02:09:27 PM CST
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
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        ListNode result(0);
        if(!head) {
            return result.next;
        }
        else {
            ListNode * p1 = head;
            ListNode * p1F = NULL;
            ListNode * p2 = head;
            for(int i = 0; i < n - 1; ++i) {
                p2 = p2->next;
            }
            while(p2->next != NULL) {
                p1F = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            if(p1F != NULL) {
                p1F->next = p1->next;
                free(p1);
            }
            else if(p1F == NULL) {
                head = head->next;
            }
            return head;
        }
    }
};

int main() {
    const int n1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode l1(0);
    ListNode * p1 = &l1; 
    
    for(unsigned i = 0; i < sizeof(n1) / sizeof(n1[0]); ++i) {
        ListNode * p1Node = new ListNode(n1[i]);
        p1->next = p1Node;
        p1 = p1->next;
    }
    
    Solution test;
    p1 = test.removeNthFromEnd(l1.next, 4);
    while(p1) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    cout << endl;
    
    return 0;
}
