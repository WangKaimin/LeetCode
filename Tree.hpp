#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include <cstdlib>
/**< Definition for binary tree */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *initTree(int arr[], int len);
#endif // TREE_HPP_INCLUDED
