#ifndef BINARYTREEZIGZAGLEVELORDERTRAVERSAL_HPP_INCLUDED
#define BINARYTREEZIGZAGLEVELORDERTRAVERSAL_HPP_INCLUDED

#include <vector>
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
    vector<vector<int> > arrs;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        //queue<TreeNode *> current;
        stack<TreeNode *> current, next;
        vector<int> arr;
        if(NULL != root)
            current.push(root);
        while(!current.empty() || !next.empty())
        {
            while(!current.empty())
            {
                root = current.top();
                current.pop();
                arr.push_back(root->val); // process
                if(NULL != root->left)
                    next.push(root->left);
                if(NULL != root->right)
                    next.push(root->right);
            }
            if(!arr.empty())
            {
                arrs.push_back(arr);
                arr.clear();
            }
            //swap(current, next);
            while(!next.empty())
            {
                root = next.top();
                next.pop();
                arr.push_back(root->val); // process
                if(NULL != root->right)
                    current.push(root->right);
                if(NULL != root->left)
                    current.push(root->left);
            }
            if(!arr.empty())
            {
                arrs.push_back(arr);
                arr.clear();
            }
        }
        return arrs;
    }

    void test()
    {
        Solution sol;
        //int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        //int n = 13, arr[15] = {1,2,3,0,0,4,0,0,5,0,6,0,0};
        int n = 7, arr[15] = {1,2,3,4,0,0,0,0,0};
        //int n = 7, arr[15] = {1,0,2,0,3,0,0};
        //int n = 3, arr[15] = {1,0,0};
        TreeNode *root = initTree(arr, n);
        preOrder(root);
        cout<<endl;
        arrs = sol.zigzagLevelOrder(root);
        for(vector< vector<int> >::iterator i = arrs.begin(); i!=arrs.end(); i++ )
        {
            for(vector<int>::iterator j = (*i).begin(); j!=(*i).end(); j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
};

#endif // BINARYTREEZIGZAGLEVELORDERTRAVERSAL_HPP_INCLUDED
