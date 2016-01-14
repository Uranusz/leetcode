// =====================================================================================
//
//       Filename:  260_single_number_3.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/03/2016 06:50:17 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:  2 states: 0 -> 1 -> 0, need 1 bit
//
//                a & ~a is a trick to keep just the lowest 1-bit of a number
// =====================================================================================
class Solution
{
    public:
        vector<int> singleNumber(vector<int>& nums)
        {
            int xorRes = 0, firstOne = 0;

            for (int n : nums)
                xorRes ^= n;

            for (int n : nums)
                if (n & (xorRes & -xorRes))
                    firstOne ^= n;

            return {firstOne, xorRes ^ firstOne};
        }

}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    vector<int> v;

    for (int i = 0; i < 23; ++i)
    {
        v.push_back(i / 2);
        cout << i / 2 << " ";
    }

    v.push_back(15);
    Solution s;
    cout << endl;

    for (int n : s.singleNumber(v))
        cout << n << " ";

    cout << endl;
    return 0;
}				// ----------  end of function main  ----------
