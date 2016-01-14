// =====================================================================================
//
//       Filename:  75_sort_colors.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/09/2016 05:31:51 PM
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
class Solution
{
    public:
        void sortColors(vector<int>& nums)
        {
            int i = 0, j = 0, k = static_cast<int>(nums.size()) - 1;

            while (j <= k)
            {
                if (nums[j] == 0)
                    swap(nums[i++], nums[j++]);
                else if (nums[j] == 1)
                    j++;
                else if (nums[j] == 2)
                    swap(nums[j], nums[k--]);
            }
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
    v.push_back(1);
    v.push_back(0);
    //v.push_back(0);
    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(0);
    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(0);
    //v.push_back(1);
    //v.push_back(2);
    Solution().sortColors(v);

    for (int i = 0; i < static_cast<int>(v.size()); ++i)
        cout << v[i] << " ";

    cout << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
