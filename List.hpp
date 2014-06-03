#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include <cstddef>
/**< Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode *l);
ListNode *initList(int arr[], int n);
#endif // LIST_HPP_INCLUDED
