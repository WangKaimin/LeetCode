#ifndef REVERSEWORDSINASTRING_HPP_INCLUDED
#define REVERSEWORDSINASTRING_HPP_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
private:
    void reverseChars(string &s)
    {

    };
public:
    void reverseWords01(string &s)
    {
        //vector<int>::iterator it;
        string::iterator it, tit;
        it = s.begin();
        while(*it == ' ')
            s.erase(it,it+1);
        reverse(it,s.end());
        while(*it == ' ')
            s.erase(it,it+1);
        tit = it;
        for(; it!=s.end(); it++)
        {
            if(' ' == *it)
            {
                reverse(tit,it);
                it++;
                while(*it == ' ')
                    s.erase(it,it+1);
                tit = it;
            }
        }
        reverse(tit,it);
    }
    void test()
    {
        Solution temp;
        string s("   wang  min   kai  ");
        //cin>>s;
        temp.reverseWords(s);
        cout<<s<<"#"<<endl;
    }
};


#endif // REVERSEWORDSINASTRING_HPP_INCLUDED
