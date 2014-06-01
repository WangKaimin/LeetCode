#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include <cstddef>
/**< Definition for binary tree */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
typedef void (*myPrint) (TreeNode *);
TreeNode *initTree(int arr[], int n);
TreeNode *buildTree(int &index, int arr[], int n);
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);
#endif // TREE_HPP_INCLUDED
