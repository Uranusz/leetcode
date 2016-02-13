// =====================================================================================
//
//       Filename:  266_palindrome_permutation.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 11:14:48 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <unordered_set>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool canPermutePalindrome(string s) {
            unordered_set<char> set;

            for (auto c : s) {
                if (set.insert(c).second == false)
                    set.erase(c);
            }

            return set.size() <= 1;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    cout << Solution().canPermutePalindrome("abccbbaa") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
