// =====================================================================================
//
//       Filename:  239_sliding_window_maximum.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/29/2016 09:23:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <deque>
#include <iostream>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> q;
            int size = nums.size();
            vector<int> res;

            for (int i = 0; i < size; ++i) {
                // 1. adjust the q
                while (!q.empty() && q.front() < i - k + 1)
                    q.pop_front();

                while (!q.empty() && nums[q.back()] < nums[i])
                    q.pop_back();

                q.push_back(i);

                if (i >= k - 1)
                    res.push_back(nums[q.front()]);
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
    vector<int> v({1, 2, 3, 3, 2, 1, 5, 5, 10});
    vector<int> res = Solution().maxSlidingWindow(v, 3);

    for (auto i : res)
        cout << i << " ";

    cout << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

