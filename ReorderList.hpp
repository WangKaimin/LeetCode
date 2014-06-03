#ifndef REORDERLIST_HPP_INCLUDED
#define REORDERLIST_HPP_INCLUDED
#include <iostream>
#include <cstddef>
#include "List.hpp"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL)
            return;
        if(NULL == head->next)
            return;

        ListNode *first = head, *second = head->next;
        ListNode *p = first, *q = second;
        ListNode *t = NULL, *pt = NULL, *qt = NULL;
        int c=0, h=0;
        while(p!=NULL)
        {
            c++;
            p = p->next;
        }
        p = first;
        h = c/2;
        while(0!=h)
        {
            q = p;
            p = p->next;
            h--;
        }
        q->next = NULL;
        second = p;
        //printList(first);
        //printList(second);


        // reverse second
        p = second;
        q = p->next;
        p->next = NULL;
        while(q != NULL)
        {
            //q = p->next;
            //ListNode * *t;
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        second = p;
        //printList(second);

        // merge
        p = first;
        q = second;

        pt = p->next;
        p->next = q;
        qt = q->next;
        while(1)
        {

            if(NULL != pt)
            {
                q->next = pt;
                p = pt;
                pt = p->next;
            }
            else
                break;

            if(qt!=NULL)
            {
                p->next = qt;
                q = qt;
                qt = q->next;
            }
            else
                break;
        }
        //printList(first);
/*
        p->next = q->next;
        p = p->next;
        while(1)
        {
            if(NULL != p->next)
            {
                q->next = p->next;
                q = q->next;
            }
            else
            {
                q->next = NULL;
                break;
            }
            if(NULL != q->next)
            {
                p->next = q->next;
                p = p->next;
            }
            else
            {
                p->next = NULL;
                break;
            }
        }
*/
    }
    void test() {
        Solution sol;
        //int n=4, arr[]={1,2,3,4};
        //int n=5, arr[]={1,2,3,4,5};
        int n=6, arr[]={1,2,3,4,5,6};
        //int n=7, arr[]={1,2,3,4,5,6,7};
        ListNode *l = initList(arr, n);
        printList(l);
        sol.reorderList(l);
        printList(l);
    }
};

#endif // REORDERLIST_HPP_INCLUDED
