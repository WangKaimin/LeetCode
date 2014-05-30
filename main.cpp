#include <iostream>
#include "ReverseWordsInAString.hpp"

using namespace std;

int main()
{
    Solution temp;
    string s("   wang  min   kai  ");
    //cin>>s;
    temp.reverseWords(s);
    cout<<s<<"#"<<endl;
    return 0;
}
