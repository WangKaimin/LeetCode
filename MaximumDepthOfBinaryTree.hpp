#ifndef MAXIMUMDEPTHOFBINARYTREE_HPP_INCLUDED
#define MAXIMUMDEPTHOFBINARYTREE_HPP_INCLUDED
#include <iostream>
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
    int getDepth(TreeNode *root)
    {
        if(root!=NULL)
        {
            int i=0, j=0;
            i = getDepth(root->left);
            j = getDepth(root->right);
            return i > j ? i+1 : j+1;
        }
        else
            return 0;
    }
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        depth = getDepth(root);
        //cout<<depth<<endl;
        return depth;
    }
    void test() {
        Solution sol;
        //int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};
        //int n = 13, arr[15] = {1,2,3,0,0,4,0,0,5,0,6,0,0};
        int n = 7, arr[15] = {1,2,3,4,0,0,0,0,0};
        //int n = 7, arr[15] = {1,0,2,0,3,0,0};
        //int n = 3, arr[15] = {1,0,0};
        TreeNode *root = initTree(arr, n);
        cout<<sol.maxDepth(root)<<endl;
    }
};

#endif // MAXIMUMDEPTHOFBINARYTREE_HPP_INCLUDED
