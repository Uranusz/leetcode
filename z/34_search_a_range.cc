// =====================================================================================
//
//       Filename:  34_search_a_range.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/14/2016 11:13:09 PM
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
class Solution
{
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            int lb = lower_bound(nums, target);
            int rb = lower_bound(nums, target + 1) - 1;

            if (lb < static_cast<int>(nums.size()) && nums[lb] == target)
                return {lb, rb};
            else
                return { -1, -1};
        }

        //-----------------------------------------------------------------------------
        // can use binary search to find left bound or right bound.
        // 1. left bound  - if(nums[mid] < target) else ...
        // 2. right bound - if(nums[mid] > target) else ...
        //-----------------------------------------------------------------------------
        int lower_bound(vector<int>& nums, int target)
        {
            int l = 0, r = nums.size() - 1;

            while (l <= r)
            {
                int mid = (l + r) / 2;

                if (nums[mid] < target)
                    l = mid + 1;
                else  // find the lower bound, so when nums[mid] == target, we still
                    // need to move left
                    r = mid - 1;
            }

            return l;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    vector<int> v;
    Solution().searchRange(v, 1);
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
