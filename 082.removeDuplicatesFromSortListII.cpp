/*************************************************************************
	> File Name: 082.removeDuplicatesFromSortListII.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/2 19:33:56
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
            ListNode * fakeHead = head;
            while(m != NULL) {
                if(l->val != m->val) {
                    if(l->next == m) {
                        l = l->next;
                        m = m->next;
                    }
                    else {
                        if(fakeHead->val == l->val) {
                            if(head->val == fakeHead->val) {
                                head = m;
                            }
                            fakeHead->next = m;
                            fakeHead = m;
                            l = m;
                            m = m->next;
                        }
                        else {
                            while(fakeHead->next != l) {
                                fakeHead = fakeHead->next;
                            }
                            fakeHead->next = m;
                            l = m;
                            m = m->next;
                        }
                    }
                }
                else {
                    m = m->next;
                }
            }
            if(head->next && head->val == head->next->val) {
                head = NULL;
            }
            if(l->next && l->val == l->next->val) {
                if(fakeHead == l) {
                    fakeHead = NULL;
                }
                else {
                    while(fakeHead->next != l) {
                        fakeHead = fakeHead->next;
                    }
                    fakeHead->next = NULL;
                }
            }
            return head;
        }
    }
};

int main() {
    const int arr[] = {1, 1, 2, 2};
    ListNode list(0);
    ListNode * pNode = &list;

    for(unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        pNode->next = new ListNode(arr[i]);
        pNode = pNode->next;
    }

    Solution test;
    ListNode * head = test.deleteDuplicates(list.next);
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
