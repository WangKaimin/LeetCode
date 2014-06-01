#ifndef MEDIANOFTWOSORTEDARRAYS_HPP_INCLUDED
#define MEDIANOFTWOSORTEDARRAYS_HPP_INCLUDED
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int C[m+n];
        int i=0, j=0, k=0;
        for(i=0, j=0, k=0;i<m && j<n; k++)
        {
            if(A[i] <= B[j])
            {
                C[k] = A[i++];
            }
            else
            {
                C[k] = B[j++];
            }
        }
        if(i!=m)
            for(; k<m+n; k++, i++)
                C[k] = A[i];
        if(j!=n)
            for(; k<m+n; k++, j++)
                C[k] = B[j];
        /*for(k=0; k<m+n; k++)
            cout<<C[k]<<endl;*/
        int t = (m+n-1)/2;
        if(0 == (m+n-1)%2)
            return C[t];
        else
            return (C[t]+C[t+1]) / 2.0;
    }
    void test()
    {
        Solution sol;
        int A[] = {1,2,5,7}, B[] = {2,3,4,6,8};
        int m=4, n=5;
        cout<<sol.findMedianSortedArrays(A,m,B,n)<<endl;
    }
};

#endif // MEDIANOFTWOSORTEDARRAYS_HPP_INCLUDED
