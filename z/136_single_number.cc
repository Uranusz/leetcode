// =====================================================================================
//
//       Filename:  137_single_number_2.cc
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
//  Description:  3 states: 0 -> 1 -> 0, need 1 bit
// =====================================================================================
class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            int bit1 = 0;

            for (unsigned int i = 0; i < nums.size(); ++i)
                bit1 = (nums[i] ^ bit1);

            return bit1;
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

    Solution s;
    cout << "result: " << s.singleNumber(v) << endl;
    return 0;
}				// ----------  end of function main  ----------
