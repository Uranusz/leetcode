// =====================================================================================
//
//       Filename:  201_bitwise_and_of_numbers_range.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/09/2016 04:15:59 PM
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
class Solution {
    public:

        int rangeBitwiseAnd(int m, int n) {
            #if 0
            // version 1
            vector<int> bits_m, bits_n;

            // 1. get each bit of m and n
            while (m || n) {
                bits_m.push_back(m % 2);
                bits_n.push_back(n % 2);
                m >>= 1;
                n >>= 1;
            }

            int result = 0;

            for (int i = static_cast<int>(bits_n.size()) - 1; i >= 0; --i) {
                if (bits_m[i] == bits_n[i])
                    result += (bits_m[i] << i);
                else
                    break;
            }

            return result;
            #else
            // 1. find equal
            int equal_part = m & n;

            if (!equal_part)
                return 0;

            // 2. find diff
            int diff_part = m ^ n;
            // 3. calculate the length of diff_part
            int length = 0;

            while (diff_part) {
                diff_part >>= 1;
                length++;
            }

            return m >> length << length;
            #endif
        }
}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    cout << Solution().rangeBitwiseAnd(5, 5) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

