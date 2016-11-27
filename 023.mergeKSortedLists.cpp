/*************************************************************************
    > File Name: 023.mergeKSortedLists.cpp
    > Author: DevilBin
    > Mail: whu.evil.binary@gmail.com
    > Created Time: Sun 27 Nov 2016 05:10:29 PM CST
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
    ListNode * mergeKLists(vector<ListNode *> & lists) {
        ListNode l(0);
        vector<int> result;
        for(size_t i = 0; i < lists.size(); ++i) {
            ListNode * head = lists[i];
            while(head != NULL) {
                result.push_back(head->val);
                head = head->next;
            }
        }
        sort(result.begin(), result.end());
        ListNode * head = &l;
        for(size_t i = 0; i < result.size(); ++i) {
            head->next = new ListNode(result[i]);
            head = head->next;
        }
        return l.next;
    }
};

int main() {
    vector<ListNode *> lists;
    ListNode l0(0), l1(0), l2(0);
    ListNode * head0 = &l0;
    ListNode * head1 = &l1;
    ListNode * head2 = &l2;
    for(int index = 0; index < 10; ++index) {
        head0->next = new ListNode(2 * index);
        head1->next = new ListNode(3 * index);
        head2->next = new ListNode(4 * index);
        head0 = head0->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    lists.push_back(l0.next);
    lists.push_back(l1.next);
    lists.push_back(l2.next);

    Solution test;
    ListNode * head = test.mergeKLists(lists);
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
