#ifndef TWONUM_HPP_INCLUDED
#define TWONUM_HPP_INCLUDED
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        for(vector<int>::size_type i=0; i<numbers.size()-1; i++)
        {
            for(vector<int>::size_type j=i+1; j<numbers.size(); j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }
        return result;
    }
    void test()
    {
        int arr[10] = {2,7,11,15}, target = 9;
        vector<int> num(arr, arr+4), result;

        Solution sol;
        result = sol.twoSum(num, target);
        for(vector<int>::iterator i=result.begin(); i!=result.end(); i++)
            cout<<*i<<endl;
    }
};

#endif // TWONUM_HPP_INCLUDED
