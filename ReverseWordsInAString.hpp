#ifndef REVERSEWORDSINASTRING_HPP_INCLUDED
#define REVERSEWORDSINASTRING_HPP_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
public:
    void reverseChars(string &s)
    {
        int i=0, j=0;
        int len = s.length();
        for(i=0, j=len; i<= len/2; i++,j--)
            swap(s[i], s[j]);
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
    void reverseWords02(string &s)
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
        temp.reverseChars(s);
        cout<<s<<"#"<<endl;
    }
};


#endif // REVERSEWORDSINASTRING_HPP_INCLUDED
