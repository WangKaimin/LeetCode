#ifndef SINGLENUMBERII_HPP_INCLUDED
#define SINGLENUMBERII_HPP_INCLUDED

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int m = sizeof(int)*8;
        int w[m], result;
        fill_n(&w[0], m, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                w[j] += (A[i] >> j)&1;
                w[j] %= 3;
            }
        result = 0;
        for(int i=0; i<m; i++)
            result += w[i]<<i;
        return result;
    }
    void test()
    {
        Solution sol;
        int A[] = {1,4,6,1,4,6,3,4,1,6};
        int result;
        for(int i=0; i<10-1; i++)
            cout<< A[i] << " ";
        cout<<endl;
        result=sol.singleNumber(A, 10);
        cout<< "Result = " << result <<endl;

    }
};


#endif // SINGLENUMBERII_HPP_INCLUDED
