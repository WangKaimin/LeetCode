#ifndef BINARYTREELEVELORDERTRAVERSAL_HPP_INCLUDED
#define BINARYTREELEVELORDERTRAVERSAL_HPP_INCLUDED
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
    int count1(int c)
    {
        int i = 0;
        while(0 != c)
        {
            c &= c-1;
            i++;
        }
        return i;
    }
public:
    vector<vector<int> > levelOrder01(TreeNode *root) {
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
            arrs.push_back(arr);
            arr.clear();
            swap(current, next);
        }
        return arrs;
    }
    /* wrong answer, full tree */
    vector<vector<int> > levelOrder_error(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> arr;
        int c = 0;
        if(NULL != root)
            q.push(root);
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            c++;
            if(count1(c) == 1 && c!=1)
            {
                arrs.push_back(arr);
                arr.clear();
            }
            if(NULL != root)
            {
                arr.push_back(root->val); // process
            }
            /*if(NULL != root->left)
                q.push(root->left);
            if(NULL != root->right)
                q.push(root->right);*/
            if(NULL != root)
            {
                q.push(root->left);
                q.push(root->right);
            }
        }
        if(!arr.empty())
            arrs.push_back(arr);
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
        arrs = sol.levelOrder01(root);
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

#endif // BINARYTREELEVELORDERTRAVERSAL_HPP_INCLUDED
