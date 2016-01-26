// =====================================================================================
//
//       Filename:  1_two_sum.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/26/2016 09:13:18 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <map>
#include <iostream>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            map<int, int> m;

            for (unsigned int i = 0; i < nums.size(); ++i) {
                if (m.find(nums[i]) != m.end()) {
                    result.push_back(m.at(nums[i]) + 1);
                    result.push_back(i + 1);
                    return result;
                }

                m.insert(pair<int, int>(target - nums[i], i));
            }

            return result;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v({1, 9, 10, 8, 2});
    vector<int> res = Solution().twoSum(v, 9);
    cout << res[0] << ", " << res[1] << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
