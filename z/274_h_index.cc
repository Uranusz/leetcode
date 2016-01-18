// =====================================================================================
//
//       Filename:  274_h_index.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/14/2016 09:58:27 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            // 1. sort it first
            sort(citations.begin(), citations.end());
            int start = citations.size();

            for (unsigned int i = 0; i < citations.size(); ++i)
                if (citations[i] < start)
                    start--;

            return start;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    cout << Solution().hIndex(v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
