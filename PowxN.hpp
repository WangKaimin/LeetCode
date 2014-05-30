#ifndef POWXN_HPP_INCLUDED
#define POWXN_HPP_INCLUDED

#include <iostream>
#include <algorithm>
using namespace std;
/**<
x = x^(n/2) * x^(n/2) * x^(n%2)
*/
class Solution
{
private:
    double mypow01(double x, unsigned n)
    {
        double result=1.0;
        while(n--)
        {
            result *= x;
        }
        return result;
    }
private:
    double mypow02(double x, unsigned int n)
    {
        if(0 == x)
            return 0;
        else if(0 == n)
            return 1;
        else if(1 == n)
            return x;
        return mypow02(x, n/2) * mypow02(x, n/2) * mypow02(x, n%2);

    }
private:
    double mypow03(double x, unsigned int n)
    {
        double t;
        if(0 == x)
            return 0;
        else if(0 == n)
            return 1;
        else if(1 == n)
            return x;
        t = mypow03(x, n/2);
        t *= t;
        if(1 == n%2)
            t *= x;
        return t;
    }
private:
    double mypow04(double x, unsigned int n)
    {
        double t = x;
        unsigned int uiNum = (unsigned int)1 << (sizeof(unsigned int)*8 - 1);
        if(0 == n)
            return 1;
        /**< find first !0 bit in uiNum */
        while((uiNum&n) == 0)
            uiNum =  uiNum >> 1;
        uiNum = uiNum >> 1;
        while(uiNum != 0)
        {
            t *= t;
            if(0 != (uiNum&n))
                t *= x;
            uiNum =  uiNum >> 1;
        }
        return t;
    }
private:
    double mypow05(double x, unsigned int n)
    {
        double t = x;
        unsigned int uiNum = 1, uiNumN = n;
        if(0 == n)
            return 1;
        /**< find first !0 bit int uiNum */
        while(1 != uiNumN)
        {
            uiNum =  uiNum << 1;
            uiNumN = uiNumN >> 1;
        }
        uiNum = uiNum >> 1;
        while(uiNum != 0)
        {
            t *= t;
            if(0 != (uiNum&n))
                t *= x;
            uiNum =  uiNum >> 1;
        }
        return t;
    }
public:
    double pow(double x, int n)
    {
        double num = mypow04(x, abs(n));
        if(0 >= n)
            return 1.0/num;
        else
            return num;
    }
    void test()
    {
        Solution sol;
        cout<<sol.pow(2.0, 7)<<endl;
        cout<<sol.pow(0.00001, 2147483647)<<endl;
    }
};

#endif // POWXN_HPP_INCLUDED
