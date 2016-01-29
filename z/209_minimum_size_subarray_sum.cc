// =====================================================================================
//
//       Filename:  209_minimum_size_subarray_sum.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/29/2016 10:04:46 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <vector>
#include <limits>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            if (nums.size() == 0)
                return 0;

            int begin = 0, end = 0, minSize = numeric_limits<int>::max();
            int head = 0;
            int sum = 0, size = nums.size();

            while (end < size) {
                sum += nums[end++];

                while (sum >= s) {
                    if (minSize > end - begin) {
                        minSize = end - begin;
                        head = begin;
                    }

                    sum -= nums[begin++];
                }
            }

            cout << "start loc: " << head << endl;
            return minSize == numeric_limits<int>::max() ? 0 : minSize ;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    //vector<int> v({2,3,1,2,4,3,2});
    vector<int> v({4});
    cout << Solution().minSubArrayLen(2, v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
