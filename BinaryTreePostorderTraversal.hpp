#ifndef BINARYTREEPOSTORDERTRAVERSAL_HPP_INCLUDED
#define BINARYTREEPOSTORDERTRAVERSAL_HPP_INCLUDED

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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        TreeNode *q = NULL;
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
            s.pop();
            if(NULL != root)
            {
                if(root->right != q)
                {
                    s.push(root);
                    root = root->right;
                    s.push(root);
                    q = root;
                }
                else
                {
                    v.push_back(root->val);
                    q = root;
                    root = NULL;
                }
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
        v = sol.postorderTraversal(root);
        for(vector<int>::iterator i = v.begin(); i!=v.end(); i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

#endif // BINARYTREEPOSTORDERTRAVERSAL_HPP_INCLUDED
