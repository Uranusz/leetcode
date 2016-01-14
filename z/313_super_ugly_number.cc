// =====================================================================================
//
//       Filename:  313_super_ugly_number.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/05/2016 08:58:39 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution
{
    public:
        #if 1
        int nthSuperUglyNumber(int n, vector<int>& primes)
        {
            // 1. keep the indexes
            vector<int> idx(primes.size(), 0);
            vector<int> list(1, 1);
            typedef unsigned int uint;

            for (int i = 0; i < n - 1; ++i)
            {
                int num = numeric_limits<int>::max();

                // find the min number
                for (uint j = 0; j < primes.size(); ++j)
                    num = min(num, list[idx[j]] * primes[j]);

                list.push_back(num);

                // upate idx
                for (uint j = 0; j < primes.size(); ++j)
                    if (num == (list[idx[j]] * primes[j]))
                        idx[j]++;
            }

            return list.back();
        }
        #else
        // faster one
        int nthSuperUglyNumber(int n, vector<int>& primes)
        {
            vector<int> factors = primes;
            vector<int> list(1, 1);
            int idx[primes.size()] = {0};

            for (int i = 0; i < n - 1; ++i)
            {
                int minNum = numeric_limits<int>::max();

                for (int n : factors)
                    minNum = min(minNum, n);

                list.push_back(minNum);

                for (uint j = 0; j < factors.size(); ++j)
                    if (minNum == factors[j])
                        factors[j] = primes[j] * list[++idx[j]];
            }

            return list.back();
        }
        #endif
}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(13);
    v.push_back(19);
    cout << "res: " << Solution().nthSuperUglyNumber(12000, v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
