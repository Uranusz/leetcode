// =====================================================================================
//
//       Filename:  319_bulb_switcher.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/06/2016 09:42:22 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <math.h>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution
{
    public:
        int bulbSwitch(int n)
        {
            return sqrt(n);
        }
}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    cout << Solution().bulbSwitch(10) << endl;
    return 0;
}				// ----------  end of function main  ----------
