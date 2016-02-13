// =====================================================================================
//
//       Filename:  1_two_sum.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/10/2016 02:13:59 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <map>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> m;

            for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
                auto it = m.find(target - nums[i]);

                if (it != m.end())
                    return vector<int>({i + 1, it->second});
                else
                    m.insert(make_pair(nums[i], i + 1));
            }

            return vector<int>({ -1, -1});
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v({1, 2, 3, 4 , 5 , 6});
    auto res = Solution().twoSum(v, 7);

    for (auto n : res)
        cout << n << " ";

    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
