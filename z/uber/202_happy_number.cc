// =====================================================================================
//
//       Filename:  202_happy_number.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 07:47:14 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int> visited;
            int curr_num = n, new_num = 0;

            while (curr_num > 0) {
                while (curr_num > 0) {
                    new_num += pow(curr_num % 10, 2);
                    curr_num /= 10;
                }

                if (new_num == 1)
                    return true;

                if (visited.insert(new_num).second == false)
                    return false;

                curr_num = new_num;
                new_num = 0;
            }

            return false;
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
    cout << s.isHappy(10011) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
