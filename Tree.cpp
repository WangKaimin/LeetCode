#include "Tree.hpp"

using namespace std;
#include <iostream>
void visit(TreeNode *root)
{
    cout<<root->val<<" ";
}

void preOrder(TreeNode *root)
{
    if(NULL == root)
        return;
    visit(root);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode *root)
{
    if(NULL == root)
        return;
    inOrder(root->left);
    visit(root);
    inOrder(root->right);
}
void postOrder(TreeNode *root)
{
    if(NULL == root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    visit(root);
}
TreeNode *buildTree(int &index, int arr[], int n)
{
    if(index == n)
        return NULL;
    /*TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->left = NULL;
    p->right = NULL;
    p->val = val;*/
    if(0 == arr[index])
    {
        index++;
        return NULL;
    }
    else
    {
        TreeNode *root = new TreeNode(arr[index++]);
        root->left = buildTree(index, arr, n);
        root->right = buildTree(index, arr, n);
        return root;
    }
}

TreeNode *initTree(int arr[], int n)
{
    int index = 0;
    return buildTree(index, arr, n);
}
