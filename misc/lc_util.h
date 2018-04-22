#ifndef __LC_UTIL_H__
#define __LC_UTIL_H__
#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_list(const vector<int> &a) {
    ListNode *head = NULL;
    ListNode *p = NULL;
    for (const int &i: a) {
        ListNode *q = new ListNode(i);
        if (head == NULL) {
            head = p = q;
        } else {
            p->next = q;
            p = q;
        }
    }
    return head;
}

void print_list(ListNode *head){
    while (head != NULL) {
        cout << head->val << (head->next == NULL? "": "->");
        head = head->next;
    }
    cout << endl;
}

template <typename T>
void print_array(const vector<T> &result) {
    for (auto &r: result) {
        cout << r << ", ";
    }
    cout << endl;
}

template <typename T>
void print_array_array(const vector<vector<T>> &results) {
    for (auto &result: results) {
        print_array(result);
    }
}


#endif

