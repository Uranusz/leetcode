// =====================================================================================
//
//       Filename:  15_three_sum.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/26/2016 09:47:48 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // sort array first
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;

            for (unsigned int i = 0; i < nums.size(); ++i) {
                if ((i > 0) && (nums[i] == nums[i - 1]))
                    continue;

                int l = i + 1, r = nums.size() - 1;

                while (l < r) {
                    int s = nums[i] + nums[l] + nums[r];

                    if (s > 0)
                        r--;
                    else if (s < 0)
                        l++;
                    else {
                        res.push_back(vector<int> ({nums[i], nums[l], nums[r]}));

                        do {
                            l++;
                        } while (l < r && nums[l - 1] == nums[l]);

                        do {
                            r--;
                        } while (r > l && nums[r + 1] == nums[r]);
                    }
                }
            }

            return res;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    Solution s;
    vector<int> v({ -2, 0, 1, 1, 2});
    auto res = s.threeSum(v);

    for (auto vec : res) {
        for (auto i : vec)
            cout << i << " ";

        cout << endl;
    }

    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
