// =====================================================================================
//
//       Filename:  330_patch_array.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/06/2016 11:27:13 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
        int minPatches(vector<int>& nums, int n) {
            int miss = 1, i = 0, added = 0;

            while (miss <= n) {
                if (i < static_cast<int>(nums.size())
                        && nums[i] <= miss) // nums[i] == miss can be also used
                    miss += nums[i++];
                else {
                    miss += miss;
                    added++;
                }
            }

            return added;
        }
};

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v({1, 3});
    cout << Solution().minPatches(v, 60) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
