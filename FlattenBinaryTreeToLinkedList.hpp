#ifndef FLATTENBINARYTREETOLINKEDLIST_HPP_INCLUDED
#define FLATTENBINARYTREETOLINKEDLIST_HPP_INCLUDED
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
public:
    void helper(TreeNode *root, TreeNode *&head1, TreeNode *&tail2)
    {
        TreeNode *tail1 = NULL, *head2 = NULL;
        if(NULL == root)
            return;

        if(NULL != root->left)
            helper(root->left, head1, tail1);
        else
        {
            head1 = tail1 = root;
        }
        if(NULL != root->right)
            helper(root->right, head2, tail2);
        else
            head2 = tail2 = root;
        if(root != head1)
        {
            tail1->right = root->right;
            root->right = head1;
            root->left = NULL;
            head1 = root;
        }
        if(root == tail2)
            tail2 = tail1;
    }
    void flatten(TreeNode *root) {
        TreeNode *head = NULL, *tail = NULL;
        helper(root, head, tail);
    }
    void test()
    {
        Solution sol;
        //int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        //int n = 13, arr[15] = {1,2,3,0,0,4,0,0,5,0,6,0,0};
        int n = 7, arr[15] = {1,2,3,0,0,0,0};
        //int n = 7, arr[15] = {1,0,2,0,3,0,0};
        //int n = 3, arr[15] = {1,0,0};
        TreeNode *root = initTree(arr, n);
        preOrder(root);
        cout<<endl;
        sol.flatten(root);
        while(root != NULL)
        {
            cout<<root->val<<endl;
            root = root->right;
        }
    }
};

#endif // FLATTENBINARYTREETOLINKEDLIST_HPP_INCLUDED
