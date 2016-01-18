// =====================================================================================
//
//       Filename:  306_additive_number.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/17/2016 07:31:54 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (),
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <string> // for use of stol, stoul

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool isAdditiveNumber(string num) {
            typedef unsigned int uint;
            typedef unsigned long ulong;
            uint size = num.size();

            for (uint i = 1; i <= size / 2; ++i) {
                if (i > 1 && num[0] == '0')
                    return false;

                for (uint j = i + 1; max(i, j - i) <= size - j; ++j) {
                    if (j - i > 1 && num[i] == '0')
                        continue;

                    ulong n1 = stoul(num.substr(0, i));
                    ulong n2 = stoul(num.substr(i, j - i));
                    string substr = num.substr(j);

                    if (isAdditive(substr, n1, n2))
                        return true;
                }
            }

            return false;
        }

        bool isAdditive(string num, ulong n1, ulong n2) {
            if (0 == num.size())
                return true;

            ulong sum = n1 + n2;
            string sum_s = to_string(sum);

            if (0 == num.compare(0, sum_s.size(), sum_s))
                return isAdditive(num.substr(sum_s.size()), n2, sum);

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
    cout << Solution().isAdditiveNumber("123") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

