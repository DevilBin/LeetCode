/*************************************************************************
	> File Name: 086.partitionList.cpp
	> Author: DevilBin 
	> Mail: whu.evil.binary@gmail.com 
	> Created Time: 2016/3/3 11:03:50
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
    ListNode * partition(ListNode * head, int x) {
        if(head == NULL) {
            return head;
        }
        else {
            ListNode min(0), max(0);
            ListNode * current = head;
            ListNode * minNode = &min;
            ListNode * maxNode = &max;
            while(current != NULL) {
                if(current->val < x) {
                    minNode->next = new ListNode(current->val);
                    minNode = minNode->next;
                }
                else {
                    maxNode->next = new ListNode(current->val);
                    maxNode = maxNode->next;
                }
                current = current->next;
            }
            minNode->next = max.next;
            return min.next;
        }
    }
};

int main() {
    const int arr[] = {1, 4, 3, 2, 5, 2};
    ListNode pNode(0);
    ListNode * head = &pNode;

    for(unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        head->next = new ListNode(arr[i]);
        head = head->next;
    }

    Solution test;
    head = test.partition(pNode.next, 3);

    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
