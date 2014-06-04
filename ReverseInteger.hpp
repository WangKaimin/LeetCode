#ifndef REVERSEINTEGER_HPP_INCLUDED
#define REVERSEINTEGER_HPP_INCLUDED

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
    int reverse(int x) {
        if(x < 0)
            return (-1)*helper(-x);
        else
            return helper(x);
    }
};

#endif // REVERSEINTEGER_HPP_INCLUDED
