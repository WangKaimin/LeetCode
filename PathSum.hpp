#ifndef PATHSUM_CPP_INCLUDED
#define PATHSUM_CPP_INCLUDED

#include "Tree.hpp"

using namespace std;

class Solution
{
private:
    bool bResult = false;
private:
    /**< only when sum >=0  */
    bool hasPathSum01(TreeNode *root, unsigned int sum)
    {
        if(NULL == root)
            return false;
        if(sum <= 0)
        {
            return false;
        }
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                if(0 == sum - root->val)
                    return true;
                else
                    return false;
            }
            if(root->left != NULL)
                return hasPathSum(root->left, sum - root->val);
            if(root->right != NULL)
            {
                return hasPathSum(root->right, sum-root->val);
            }
        }
    }
private:
    void hasPathSum02(TreeNode *root, int sum)
    {
        if(NULL == root)
            return;
        if(bResult)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            if(0 == (sum - (root->val)))
                bResult = true;
            else
                return;
        }
        if(root->left != NULL)
            hasPathSum(root->left, sum - (root->val));
        if(root->right != NULL)
            hasPathSum(root->right, sum - (root->val));
    }
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        hasPathSum02(root, sum);
        return bResult;
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
        if(sol.hasPathSum(root, 0))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
};

#endif // PATHSUM_CPP_INCLUDED
