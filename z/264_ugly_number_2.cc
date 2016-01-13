// =====================================================================================
//
//       Filename:  264_ugly_number_2.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/05/2016 09:47:53 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
public:
    int nthUglyNumber(int n) {
        int primes[3] = {2, 3, 5};
        int indexes[3] = {0, 0, 0};

        vector<int> uglyNums(1, 1);

        for(int i = 0; i < n - 1; ++i) {
            // find min number
            int minNum = numeric_limits<int>::max();
            for (int j = 0; j < 3; ++j)
                minNum = min(minNum, uglyNums[indexes[j]] * primes[j]);

            uglyNums.push_back(minNum);

            // update index
            for (int j = 0; j < 3; ++j)
                if (minNum == uglyNums[indexes[j]] * primes[j])
                    indexes[j]++;
        }

        return uglyNums.back();
    }
}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main ( int argc, char *argv[] ) {

    cout << "res: " << Solution().nthUglyNumber(12) << endl;
    return EXIT_SUCCESS;
}

