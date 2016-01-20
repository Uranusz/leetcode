// =====================================================================================
//
//       Filename:  326_power_of_three.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/12/2016 11:08:59 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool isPowerOfThree(int n) {
            int max = 1162261467; // maximum number which is power of 3
            return n > 0 ? !(max % n) : 0;
        }

}; // -----  end of class Solution  -----


#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    cout << Solution().isPowerOfThree(100) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
