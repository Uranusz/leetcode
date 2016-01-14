// =====================================================================================
//
//       Filename:  287_duplicate_number.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/03/2016 09:58:22 PM
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
//  Description:  1. treat the nums as a linked-list, each element is the pointer
//                   pointing to next element
//                2. this array has duplicate numbers which means that for the linked-
//                   list, it has nodes pointing to another same node, so it must be
//                   cyclic
//                3. solve this problem using slow and fast pointer
// =====================================================================================
class Solution
{
    public:
        int findDuplicate(vector<int>& nums)
        {
            if (nums.size() <= 1)
                return -1;

            int slow = nums[0], fast = nums[nums[0]];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;

            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }

            return slow;
        }

}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(6);
    v.push_back(0);
    cout << Solution().findDuplicate(v) << endl;
    return 0;
}				// ----------  end of function main  ----------
