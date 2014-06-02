#ifndef SAMETREE_HPP_INCLUDED
#define SAMETREE_HPP_INCLUDED
#include <stack>
#include "Tree.hpp"
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isSameNode(TreeNode *p, TreeNode *q)
    {
        if(NULL==p && NULL==q)
            return true;
        else if(p==NULL && NULL != q)
            return false;
        else if(NULL!=p && NULL == q)
            return false;
        if(p->val != q->val)
            return false;
        if((p->left!=NULL) && (NULL == q->left))
            return false;
        else if((p->left==NULL) && (NULL != q->left))
            return false;
        if((p->right!=NULL) && (NULL == q->right))
            return false;
        else if((p->right==NULL) && (NULL != q->right))
            return false;
        return true;
    }
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> s1, s2;
        if(!isSameNode(p, q))
            return false;
        else if(p != NULL)
        {
            s1.push(p);
            s2.push(q);
        }
        while(!s1.empty())
        {
            p = s1.top();
            q = s2.top();
            if(!isSameNode(p, q))
                return false;
            s1.pop();
            s2.pop();
            if(NULL != p->right)
            {
                s1.push(p->right);
                s2.push(q->right);
            }
            if(NULL != p->left)
            {
                s1.push(p->left);
                s2.push(q->left);
            }
        }
        return true;
    }
    void test()
    {
        Solution sol;
        //int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        int n = 13, arr[15] = {1,2,3,0,0,4,0,0,5,0,6,0,0};
        //int n = 7, arr[15] = {1,2,3,4,0,0,0,0,0};
        //int n = 7, arr[15] = {1,0,2,0,3,0,0};
        //int n = 3, arr[15] = {1,0,0};
        TreeNode *root = initTree(arr, n);
        bool b;
        preOrder(root);
        cout<<endl;
        b = sol.isSameTree(NULL, root);
        if(b)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
};

#endif // SAMETREE_HPP_INCLUDED
