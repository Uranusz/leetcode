// =====================================================================================
//
//       Filename:  275_h_index.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/14/2016 10:28:05 PM
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
        int hIndex(vector<int>& citations)
        {
            int size = static_cast<int>(citations.size());
            int left = 0, right = size - 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;

                if (citations[mid] < size - mid)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            return size - left;
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
    //for(int i = 0; i < 6; ++i)
    //    v.push_back(i-1);
    cout << Solution().hIndex(v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

