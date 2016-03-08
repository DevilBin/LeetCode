/*************************************************************************
	> File Name: 092.reverseLinkedListII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/8 18:42:53
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        ListNode * fakeHead = new ListNode(0);
        fakeHead->next = head;
        if(!head || !head->next || m == n) {
            return head;
        }
        else {
            int i = 0;
            ListNode * p = fakeHead;
            while(i < m - 1 && p != NULL) {
                p = p->next;
                i++;
            }
            ListNode * q = p->next;
            ListNode * r = q->next;
            ListNode * lastNode = q;
            p->next = NULL;
            while(i < n) {
                q->next = p->next;
                p->next = q;
                q = r;
                if(r != NULL) {
                    r = r->next;
                }
                i++;
            }
            lastNode->next = q;
            return fakeHead->next;
        }
    }
};

int main() {
    const int arr[] = {1, 2, 3, 4, 5};
    ListNode pNode(0);
    ListNode * head = &pNode;

    for(unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        head->next = new ListNode(arr[i]);
        head = head->next;
    }

    Solution test;
    ListNode * result = test.reverseBetween(pNode.next, 4, 5);

    while(result != NULL) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
    return 0;
}
