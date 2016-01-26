// =====================================================================================
//
//       Filename:  198_house_robber.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/26/2016 08:15:43 PM
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
//  Description:
// =====================================================================================
class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;

            if (nums.size() == 1)
                return nums[0];

            int curr = nums[0], prev = 0;

            for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
                int tmp = curr;
                curr = max(curr, prev + nums[i]);
                prev = tmp;
            }

            return curr;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v({1, 8, 10, 2, 1, 1, 9});
    cout << Solution().rob(v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
