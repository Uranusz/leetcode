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
//  Description:  3 states: 00 -> 01 -> 10 -> 00, need 2 bits
// =====================================================================================
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit1 = 0, bit2 = 0;

        for(unsigned int i = 0; i < nums.size(); ++i) {
            bit1 = (nums[i] ^ bit1) & ~bit2;
            bit2 = (nums[i] ^ bit2) & ~bit1;
        }

        cout << "bit1: " << bit1 << ", bit2: " << bit2 << endl;
        return bit1;
    }

}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main ( int argc, char *argv[] ) {
    vector<int> v;

    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);

    //for(int i = 0; i < 22; ++i)
    //{
    //    v.push_back(i/3);
    //    cout << i/3 << " ";
    //}

    cout << endl << endl;;

    Solution s;
    cout << "result: " << s.singleNumber(v) << endl;

    return 0;
}				// ----------  end of function main  ----------
