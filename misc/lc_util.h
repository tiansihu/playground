#ifndef __LC_UTIL_H__
#define __LC_UTIL_H__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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

