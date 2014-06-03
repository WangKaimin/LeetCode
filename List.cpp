#include "List.hpp"
#include <iostream>
using namespace std;
void printList(ListNode *l)
{
    if(NULL == l)
        return;
    while(l!=NULL && l->next != NULL)
    {
        cout<<l->val<<" ";
        l = l->next;
    }
    cout<<l->val<<endl;
}
ListNode *initList(int arr[], int n)
{
    ListNode head(0);
    ListNode *p = &head;
    if(0 == n)
        return NULL;
    for(int i=0; i<n; i++)
    {
        ListNode *node = new ListNode(arr[i]);
        p->next = node;
        p = p->next;
    }
    return head.next;
}
