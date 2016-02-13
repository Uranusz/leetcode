// =====================================================================================
//
//       Filename:  290_word_pattern.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 07:25:58 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            unordered_map<char, string> cmap;
            unordered_set<string> used_strs;
            stringstream ss(str);
            string s;

            for (auto c : pattern) {
                if (!(ss >> s))
                    return false;

                if (cmap.count(c) == 0) {
                    // insert return a pair - (iterator, bool)
                    if (!used_strs.insert(s).second)
                        return false;

                    cmap.emplace(c, s);
                } else if (cmap[c] != s)
                    return false;
            }

            return !(ss >> s);
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    Solution s;
    cout << s.wordPattern("aabbb", "a a b b b") << endl;
    cout << s.wordPattern("aicb", " x ly z t") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
