// =====================================================================================
//
//       Filename:  8_string_to_integer.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 11:22:48 PM
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
        int myAtoi(string str) {
            int sum = 0;

            for (auto c : str) {
                if (c - '0' > 9)
                    return -1;

                sum = sum * 10 + c - '0';
            }

            cout << sum << endl;
            return sum;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    cout << Solution().myAtoi("1234");
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
