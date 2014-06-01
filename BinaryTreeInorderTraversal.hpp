#ifndef BINARYTREEINORDERTRAVERSAL_HPP_INCLUDED
#define BINARYTREEINORDERTRAVERSAL_HPP_INCLUDED

#include "Tree.hpp"
#include <stack>
#include <vector>
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
    vector<int> inorderTraversal03(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        while(!s.empty() || NULL != root)
        {
            if(NULL != root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                v.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return v;
    }
    vector<int> inorderTraversal02(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if(NULL != root)
            s.push(root);
        while(!s.empty())
        {
            while(root != NULL)
            {
                s.push(root->left);
                root = root->left;
            }
            root = s.top();
            if(NULL != root)
                v.push_back(root->val);
            s.pop();
            if(root != NULL)
            {
                s.push(root->right);
                root = root->right;
            }
        }
        return v;
    }
    vector<int> inorderTraversal01(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if(NULL != root)
            s.push(root);
        while(!s.empty())
        {
            while(root != NULL)
            {
                s.push(root->left);
                root = root->left;
            }
            root = s.top();
            if(NULL != root)
                v.push_back(root->val);
            s.pop();
            if(root != NULL)
            {
                s.push(root->right);
                root = root->right;
            }
        }
        return v;
    }
    void test()
    {
        Solution sol;
        vector<int> v;
        int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        TreeNode *root = initTree(arr, n);
        v = sol.inorderTraversal02(root);
        for(vector<int>::iterator i = v.begin(); i!=v.end(); i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

#endif // BINARYTREEINORDERTRAVERSAL_HPP_INCLUDED
