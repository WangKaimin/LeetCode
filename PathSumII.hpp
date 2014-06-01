#ifndef PATHSUMII_HPP_INCLUDED
#define PATHSUMII_HPP_INCLUDED

#include <vector>
#include <stack>
#include "Tree.hpp"
using namespace std;

struct temp_s
{
    TreeNode *root;
    int sum;
    int index;
};

class Solution
{
private:
    vector< vector<int> > arrs;
    void setMyStackData(temp_s &s, TreeNode *root, int index, int sum)
    {
        s.index = index;
        s.root  = root;
        s.sum   = sum;
        return;
    }
    void helper01(TreeNode *root, int sum, vector<int> &arr, int index)
    {
        if(NULL == root)
            return;
        arr.insert(arr.begin()+index, root->val);
        if(NULL == root->left && NULL == root->right)
        {

            if(0 == sum-(root->val))
            {
                vector<int> t_arr;
                t_arr.assign(arr.begin(), index+1+arr.begin());
                arrs.push_back(t_arr);
            }
            return;
        }
        if(NULL != root->left)
            helper01(root->left, sum - (root->val), arr, index+1);
        if(NULL != root->right)
            helper01(root->right, sum - (root->val), arr, index+1);
        return;
    }
    void helper02(TreeNode *root, int sum, vector<int> &arr, int index)
    {
        stack<TreeNode *> s_tree;
        stack<int> s_sum;
        stack<int> s_index;

        if(NULL == root)
            return;

        s_tree.push(root);
        s_sum.push(sum);
        s_index.push(index);

        while(!s_tree.empty())
        {
            root = s_tree.top();
            sum = s_sum.top();
            index = s_index.top();

            s_tree.pop();
            s_sum.pop();
            s_index.pop();

            arr.insert(arr.begin()+index, root->val);
            if(NULL == root->left && NULL == root->right)
            {
                if(0 == sum-(root->val))
                {
                    vector<int> t_arr;
                    t_arr.assign(arr.begin(), index+1+arr.begin());
                    arrs.push_back(t_arr);
                }
            }

            if(root->right != NULL)
            {
                s_tree.push(root->right);
                s_sum.push(sum-(root->val));
                s_index.push(index+1);
            }
            if(root->left != NULL)
            {
                s_tree.push(root->left);
                s_sum.push(sum-(root->val));
                s_index.push(index+1);
            }
        }
        return;
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<int> arr;
        int index=0;
        helper02(root, sum, arr, index);
        return arrs;
    }
    void test()
    {
        Solution sol;
        TreeNode *root;

        int n = 15, arr[15] = {1,-2,4,-1,0,0,0,3,0,0,-3,2,0,0,0};

        /*cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];*/
        root = initTree(arr, n);
        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
        sol.pathSum(root, 2);
        vector< vector<int> > arrs(sol.arrs);
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

#endif // PATHSUMII_HPP_INCLUDED
