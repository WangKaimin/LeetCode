#ifndef PALINDROMENUMBER_HPP_INCLUDED
#define PALINDROMENUMBER_HPP_INCLUDED

class Solution {
private:
    unsigned int helper(unsigned int x){
        unsigned result = 0 , y = 0;
        while(1)
        {
            y = x%10;
            x = x/10;
            if(x == 0)
            {
                return result+y;
            }
            result = 10*result + 10*y;
        }
    }
public:
    bool isPalindrome02(int x) {
        if(x < 0)
            return false;
        int d = 1;
        while(x/d >= 10)
            d*=10;
        while(x>0) {
            int q = x / d;
            int r = x % 10;
            if( q!=r)
                return false;
            x = x % d /10;
            d /= 100;
        }
        return true;
    }
    bool isPalindrome01(int x) {
        if(x < 0)
            return false;
        else if(x == helper(x))
            return true;
        else
            return false;
    }
};

#endif // PALINDROMENUMBER_HPP_INCLUDED
