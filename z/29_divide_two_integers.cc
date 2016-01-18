// =====================================================================================
//
//       Filename:  29_divide_two_integers.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/11/2016 09:56:08 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <limits.h>
#include	<stdlib.h>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (divisor == 0) return INT_MAX;

            if (divisor == 1) return dividend;

            if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

            unsigned int a = dividend >= 0 ? dividend : -dividend;
            unsigned int b = divisor >= 0 ? divisor : -divisor;
            unsigned int result = 0;

            while (true) {
                unsigned int c = b, k = 1;

                while (a > c) {
                    c <<= 1;
                    k <<= 1;
                }

                if (a < c) {
                    c >>= 1;
                    k >>= 1;
                }

                if (k == 0) break;

                a -= c;
                result += k;
            }

            int sign = (dividend ^ divisor) >> 31 ? -1 : 1;
            return sign == 1 ? result : -result;
        }
}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    cout << Solution().divide(-10, 3) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

