/*************************************************************************
	> File Name: 083.removeDuplicatesFromSortedList.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/2 22:56:55
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
    ListNode * deleteDuplicates(ListNode * head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        else {
            ListNode * l = head;
            ListNode * m = head->next;
            while(m != NULL) {
                if(l->val != m->val) {
                    if(l->next == m) {
                        l = l->next;
                        m = m->next;
                    }
                    else {
                        l->next = m;
                        l = m;
                        m = l->next;
                    }
                }
                else {
                    m = m->next;
                }
            }
            if(l->next && l->val == l->next->val) {
                l->next = NULL;
            }
            return head;
        }
    }
};

int main() {
    const int arr[] = {1, 2, 2};
    ListNode pNode(0);
    ListNode * head = &pNode;

    for(unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        head->next = new ListNode(arr[i]);
        head = head->next;
    }

    Solution test;
    head = test.deleteDuplicates(pNode.next);
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
