// =====================================================================================
//
//       Filename:  268_missing_number.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/03/2016 08:34:35 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
public:
    // 1. naive implementation
#if 0
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int size = nums.size();
        int expected = size*(size+1) / 2;

        return expected - sum;
    }
#else
    // 2. bit manipulation
    int missingNumber(vector<int>& nums) {
        int xorRes = 0, xorResExpected = 0;

        for(int n : nums)
            xorRes ^= n;

        for(unsigned int i = 0; i <= nums.size(); ++i)
            xorResExpected ^= i;

        return xorResExpected ^ xorRes;
    }
#endif

}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main ( int argc, char *argv[] ) {
    vector<int> v;

    for(int i = 0; i < 10; ++i)
        if(i != 9)
            v.push_back(i);

    cout << "res: " << Solution().missingNumber(v) << endl;
    return 0;
}				// ----------  end of function main  ----------
