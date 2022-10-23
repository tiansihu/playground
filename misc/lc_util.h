#ifndef __LC_UTIL_H__
#define __LC_UTIL_H__
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = NULL;
  }
};

static constexpr int NULL_VAL = -1;

/*
TreeNode *make_tree(const std::vector<int> &vals) {
    if (vals.empty()) {
        return nullptr;
    }

    auto make_tree_node = [&](int val) -> TreeNode * {
        if (val == NULL_VAL) {
            return nullptr;
        }

        return new TreeNode(val);
    };

    std::list<TreeNode *> queue;
    auto iter = vals.begin();
    TreeNode *root = make_tree_node(*iter++);
    queue.push_back(root);

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop_front();
        node->left = make_tree_node(*iter++);
        if (node->left) {
            queue.push_back(node->left);
        }

        node->right = make_tree_node(*iter++);
        if (node->right) {
            queue.push_back(node->right);
        }
    }
    return root;
}
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_list(const vector<int> &a) {
  ListNode *head = NULL;
  ListNode *p = NULL;
  for (const int &i : a) {
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

void print_list(ListNode *head) {
  while (head != NULL) {
    cout << head->val << (head->next == NULL ? "" : "->");
    head = head->next;
  }
  cout << endl;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &a) {
  for (auto &i : a) {
    out << i << ", ";
  }
  return out;
}

template <typename T> void print_array(const vector<T> &result) {
  for (auto &r : result) {
    cout << r << ", ";
  }
  cout << endl;
}

template <typename T> void print_array_array(const vector<vector<T>> &results) {
  for (auto &result : results) {
    print_array(result);
  }
}

template <typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &a) {
  for (auto &n : a) {
    out << n;
    out << endl;
  }
  return out;
}

#endif
