#ifndef SINGLENUMBERII_HPP_INCLUDED
#define SINGLENUMBERII_HPP_INCLUDED

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
        int A[] = {1,4,6,1,4,6,3,4,1,6};
        int result;
        for(int i=0; i<10; i++)
            cout<<A[i]<<endl;
        result=sol.singleNumber(A, 10);
        cout<< "Result = " <<result <<endl;

    }
};


#endif // SINGLENUMBERII_HPP_INCLUDED
