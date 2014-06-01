#ifndef ADDTWONUMBERS_HPP_INCLUDED
#define ADDTWONUMBERS_HPP_INCLUDED

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers03(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *p3 = NULL, *result = l1;
        int t = 0, sum = 0;
        if(NULL == l1)
            return l2;
        else if(NULL == l2)
            return l1;
        while(p1->next != NULL && p2->next != NULL)
        {
            sum = (p1->val + p2->val + t);
            t = sum/10;
            sum = sum%10;
            p1->val = sum;
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL)
        {
            p1->next = p2->next;
        }
        sum = (p1->val + p2->val + t);
        t = sum/10;
        sum = sum%10;
        p1->val = sum;
        p3 = p1;
        while(0 != t)
        {
            if(p1->next != NULL)
            {
                sum = p1->next->val + t;
                t = sum/10;
                sum = sum%10;
                p1->next->val = sum;
                p1 = p1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(0);
                newNode->val += t;
                p1->next = newNode;
                break;
            }
        }
        return result;
    }
    ListNode *addTwoNumbers02(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *p3 = NULL, *result = l1;
        int t = 0, sum = 0;
        if(NULL == l1)
            return l2;
        else if(NULL == l2)
            return l1;
        while(p1->next != NULL && p2->next != NULL)
        {
            sum = (p1->val + p2->val + t);
            t = sum/10;
            sum = sum%10;
            p1->val = sum;
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL)
        {
            p1->next = p2->next;
        }
        sum = (p1->val + p2->val + t);
        t = sum/10;
        sum = sum%10;
        p1->val = sum;
        p3 = p1;
        while(0 != t)
        {
            if(p1->next != NULL)
            {
                sum = p1->next->val + t;
                t = sum/10;
                sum = sum%10;
                p1->next->val = sum;
                p1 = p1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(0);
                newNode->val += t;
                p1->next = newNode;
                break;
            }
        }
        return result;
    }
    ListNode *addTwoNumbers01(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *p3 = NULL, *result = NULL;
        int t = 0, sum = 0;
        if(NULL == l1)
            return l2;
        else if(NULL == l2)
            return l1;
        while(p1->next != NULL && p2->next != NULL)
        {
            result = l1;
            sum = (p1->val + p2->val + t);
            t = sum/10;
            sum = sum%10;
            p1->val = sum;
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL)
        {
            p1->next = p2->next;
            if(result == NULL)
                result = l2;
            sum = (p1->val + p2->val + t);
            t = sum/10;
            sum = sum%10;
            p2->val = sum;
            if(p3 != NULL)
                p3->next = p2;
            p3 = p2;
            while(0 != t)
            {
                if(p2->next != NULL)
                {
                    sum = p2->next->val + t;
                    t = sum/10;
                    sum = sum%10;
                    p2->next->val = sum;
                    p2 = p2->next;
                }
                else
                {
                    ListNode *newNode = new ListNode(0);
                    newNode->val += t;
                    p2->next = newNode;
                    break;
                }
            }
        }
        else if(p2->next == NULL)
        {
            if(result == NULL)
                result = l1;
            sum = (p1->val + p2->val + t);
            t = sum/10;
            sum = sum%10;
            p1->val = sum;
            p3 = p1;
            while(0 != t)
            {
                if(p1->next != NULL)
                {
                    sum = p1->next->val + t;
                    t = sum/10;
                    sum = sum%10;
                    p1->next->val = sum;
                    p1 = p1->next;
                }
                else
                {
                    ListNode *newNode = new ListNode(0);
                    newNode->val += t;
                    p1->next = newNode;
                    break;
                }
            }
        }
        return result;
    }
    void test()
    {
        Solution sol;
        ListNode l1(7), l2(5);
        ListNode *p = sol.addTwoNumbers01(&l1, &l2);
        while(p!=NULL)
        {
            cout<<p->val<<endl;
            p = p->next;
        }
    }
};

#endif // ADDTWONUMBERS_HPP_INCLUDED
