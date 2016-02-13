// =====================================================================================
//
//       Filename:  242_valid_anagram.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/10/2016 02:01:49 PM
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
        bool isAnagram(string s, string t) {
            if (s.size() != t.size())
                return false;

            int map[256] = {0}, length = s.size();

            for (int i = 0; i < length; ++i) {
                map[static_cast<int>(s[i])]++;
                map[static_cast<int>(t[i])]--;
            }

            int mask = 0;

            for (auto count : map)
                mask |= count;

            return mask == 0;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    Solution s;
    cout << s.isAnagram("abc", "bac") << endl;
    cout << s.isAnagram("abc", "bae") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
