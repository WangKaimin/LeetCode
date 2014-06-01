#ifndef BINARYTREEPREORDERTRAVERSAL_HPP_INCLUDED
#define BINARYTREEPREORDERTRAVERSAL_HPP_INCLUDED

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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if(NULL != root)
            s.push(root);
        while(!s.empty())
        {
            root = s.top();
            v.push_back(root->val);
            s.pop();
            if(root->right != NULL)
                s.push(root->right);
            if(root->left != NULL)
                s.push(root->left);
        }
        return v;
    }
    void test()
    {
        Solution sol;
        vector<int> v;
        int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        TreeNode *root = initTree(arr, n);
        v = sol.preorderTraversal(root);
        for(vector<int>::iterator i = v.begin(); i!=v.end(); i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

#endif // BINARYTREEPREORDERTRAVERSAL_HPP_INCLUDED
