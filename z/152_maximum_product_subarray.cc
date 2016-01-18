/*
 * =====================================================================================
 *
 *       Filename:  152_maximum_prodect_subarray.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/05/2016 09:53:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

/*
 * =====================================================================================
 *        Class:  Solution
 *  Description:  check 3 use cases to find the rule
 *                1. array with only 1 negative number
 *                2. array with 2 negative number
 *                2. array with 3 negative number
 * =====================================================================================
 */
class Solution {
    public:

        /*-----------------------------------------------------------------------------
         *  use DP. Construct subarray, it always contains the rightmost element in the
         *  sub problem;
         *-----------------------------------------------------------------------------*/
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 0)
                return -1;

            int currentMax = 1, currentMin = 1;
            int result = nums[0];

            for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
                int tmp = currentMin;
                currentMin = min(*it, min(currentMin * (*it), currentMax * (*it)));
                currentMax = max(*it, max(tmp * (*it), currentMax * (*it)));
                result = max(result, currentMax);
            }

            return result;
        }

}; /* -----  end of class Solution  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(-3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    cout << Solution().maxProduct(v) << endl;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
