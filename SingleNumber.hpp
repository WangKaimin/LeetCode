#ifndef SINGLENUMBER_HPP_INCLUDED
#define SINGLENUMBER_HPP_INCLUDED

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int t=0;
        while(--n>=0)
            t ^= A[n];
        return t;
    }
    void test()
    {
        Solution sol;
        int A[] = {1,4,6,1,6,3,4};
        int result;
        for(int i=0; i<7; i++)
            cout<<A[i]<<endl;
        result=sol.singleNumber(A, 7);
        cout<< result <<endl;

    }
};

#endif // SINGLENUMBER_HPP_INCLUDED
