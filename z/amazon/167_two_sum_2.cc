// =====================================================================================
//
//       Filename:  167_two_sum_2.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/10/2016 05:18:14 PM
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


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1;

            while (l < r) {
                long val = nums[l] + nums[r];

                if (val == target)
                    return vector<int>({l + 1, r + 1});
                else if (val < target)
                    l++;
                else
                    r--;
            }

            return vector<int>();
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v({1, 2, 3, 4, 7, 9});
    auto res = s.twoSum(v, 6);

    for (auto n : res)
        cout << n << " ";

    cout << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
