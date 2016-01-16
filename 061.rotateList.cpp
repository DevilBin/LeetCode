/*************************************************************************
	> File Name: 061.rotateList.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/1/16 13:31:24
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
    ListNode * rotateRight(ListNode * head, int k) {
        int length = 1;
        ListNode * p = head;
        if(k < 0 || !head) {
            return head;
        }
        else {
            while(p->next) {
                length++;
                p = p->next;
            }
            p->next = head;
            k = length - k % length;
            while(k > 0) {
                p = p->next;
                k--;
            }
            head = p->next;
            p->next = NULL;
            return head;
        }
    }
};

int main() {
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ListNode L(0);
    ListNode * p = &L;

    for(unsigned i = 0; i < (sizeof(arr) / sizeof(arr[0])); ++i) {
        ListNode * p1Node = new ListNode(arr[i]);
        p->next = p1Node;
        p = p->next;
    }

    Solution test;
    ListNode * result = test.rotateRight(L.next, 9);
    while(result) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;
    return 0;
}
