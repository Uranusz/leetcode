// =====================================================================================
//
//       Filename:  291_word_pattern_2.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 04:27:36 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool wordPatternMatch(string pattern, string str) {
            map<char, string> m;
            set<string> strSet;
            return _wordPatternMatch(m, strSet, pattern, str);
        }

        bool _wordPatternMatch(map<char, string>& m, set<string>& strSet,
                               string pattern, string str) {
            cout << "pattern: " << pattern << ", str: " << str << endl;

            if (pattern.empty())
                return str.empty();

            if (m.find(pattern[0]) != m.end()) {
                string s = m[pattern[0]];

                if (str.length() < s.length() || str.substr(0, s.length()) != s)
                    return false;

                if (_wordPatternMatch(m, strSet, pattern.substr(1), str.substr(s.length())))
                    return true;
            } else {
                for (unsigned int i = 1; i <= str.length(); ++i) {
                    if (strSet.find(str.substr(0, i)) != strSet.end())
                        continue;

                    m.insert(make_pair(pattern[0], str.substr(0, i)));
                    strSet.insert(str.substr(0, i));

                    if (_wordPatternMatch(m, strSet, pattern.substr(1), str.substr(i)))
                        return true;

                    m.erase(pattern[0]);
                    strSet.erase(str.substr(0, i));
                }
            }

            return false;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    cout << Solution().wordPatternMatch("abb", "xyy") << endl;
    cout << Solution().wordPatternMatch("abc", "xyy") << endl;
    cout << Solution().wordPatternMatch("abc", "xyz") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
