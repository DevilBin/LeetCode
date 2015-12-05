/*************************************************************************
	> File Name: 002.addTwoNumbers.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2015/12/5 12:27:20
 ************************************************************************/

#include <iostream> 
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* pCurrent = &result;
        int carry = 0; int sum = 0;
        while(l1 || l2) {
            int num1 = (l1 ? l1->val : 0);
            int num2 = (l2 ? l2->val : 0);
            sum = num1 + num2 + carry;
            if(sum > 9) {
                carry = 1;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }

            ListNode* pNode = new ListNode(sum);
            pCurrent->next = pNode;
            pCurrent = pCurrent->next;      

            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        if(carry) {
            ListNode* pNode = new ListNode(carry);
            pCurrent->next = pNode;
            pCurrent = pCurrent->next;
        }
        return result.next;
    }
};

int main() {
    const int n1[] = {1, 8};
    const int n2[] = {9, 2, 5, 6};
    ListNode l1(0), l2(0);
    ListNode* p1 = &l1;
    ListNode* p2 = &l2;

    for(unsigned i = 0; i < 2; ++i) {
        ListNode *p1Node = new ListNode(n1[i]);
        p1->next = p1Node;
        p1 = p1->next;
    }
    for(unsigned i = 0; i < 4; ++i) {
        ListNode *p2Node = new ListNode(n2[i]);
        p2->next = p2Node;
        p2 = p2->next;
    }

    Solution test;
    p1 = test.addTwoNumbers(l1.next, l2.next);
    while(p1) {
        cout << p1->val << ' ';
        p1 = p1->next;
    }
    cout << endl;

    return 0;
}
