#ifndef BINARYTREELEVELORDERTRAVERSALII_HPP_INCLUDED
#define BINARYTREELEVELORDERTRAVERSALII_HPP_INCLUDED

#include <vector>
#include <queue>
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
    /** \brief The same to binary-tree-level-order-traversal
     *
     * \param root TreeNode*
     * \return vector<vector<int>>
     *
     */
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> current, next;
        vector<int> arr;
        if(NULL != root)
            current.push(root);
        while(!current.empty())
        {
            while(!current.empty())
            {
                root = current.front();
                current.pop();
                arr.push_back(root->val); // process
                if(NULL != root->left)
                    next.push(root->left);
                if(NULL != root->right)
                    next.push(root->right);
            }
            // different here
            arrs.insert(arrs.begin(), arr);
            arr.clear();
            swap(current, next);
        }
        return arrs;
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
        preOrder(root);
        cout<<endl;
        arrs = sol.levelOrderBottom(root);
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

#endif // BINARYTREELEVELORDERTRAVERSALII_HPP_INCLUDED
