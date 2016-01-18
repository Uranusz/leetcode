// =====================================================================================
//
//       Filename:  316_remove_duplicate_letters.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/06/2016 11:13:06 PM
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
        string removeDuplicateLetters(string s) {
            char result[26] = {'\0'};
            int count[26] = {0};
            bool seen[26] = {false};

            // count each char
            for (char c : s)
                count[c - 'a'] ++;

            int stack_top = -1;

            // simulate the stack
            for (unsigned int i = 0; i < s.length(); ++i) {
                char c = s[i];

                if (seen[c - 'a']) {
                    count[c - 'a']--;
                    continue;
                }

                while (stack_top >= 0 && c < result[stack_top]
                        && count[result[stack_top] - 'a'] > 0) {
                    seen[result[stack_top] - 'a'] = false;
                    result[stack_top--] = '\0';
                }

                result[++stack_top] = c;
                seen[c - 'a'] = true;
                count[c - 'a']--;
            }

            return string(result);
        }

}; // -----  end of class Solution  -----


// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    cout << Solution().removeDuplicateLetters("fbccddaffdec") << endl;
    return 0;
}				// ----------  end of function main  ----------
