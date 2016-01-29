// =====================================================================================
//
//       Filename:  76_minimum_window_substring.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/29/2016 10:40:33 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        string minWindow(string s, string t) {
            int start = 0, end = 0, minStart = -1, minLen = numeric_limits<int>::max();
            int counter = t.size();
            int s_size = s.size();
            unordered_map<char, int> map;

            // init the map
            for (auto c : t)
                map[c]++;

            while (end < s_size) {
                // find valid window by increasing end
                //
                if (map[s[end++]]-- > 0)
                    counter--;

                // counter == 0 means that a valid window found, then increase start to minimize
                // the window
                while (counter == 0) {
                    // update minStart and minLen before find next valid window
                    if (end - start < minLen) {
                        minStart = start;
                        minLen = end - start;
                    }

                    if (map[s[start++]]++ == 0)
                        counter++;
                }
            }

            return minLen == numeric_limits<int>::max() ? "" : s.substr(minStart, minLen);
        }
}; // -----  end of class Solution  -----

// =====================================================================================
//        Class:  Extension
//  Description:  related problems
// =====================================================================================
class Extension {
    public:
        // 1. Longest Substring with At Most Two Distinct Characters
        int lengthOfLongestSubstringTwoDistinct(string s) {
            int counter = 0, start = 0, end = 0, maxLen = 0, head = 0;
            unordered_map<char, int> map;

            while (end < static_cast<int>(s.size())) {
                if (map[s[end++]]++ == 0)
                    counter++; // counter the distinct numbers, and ignore duplicates

                // reduce the substring, counter shuld be equal two 2
                while (counter > 2) {
                    if (map[s[start++]]-- == 1)
                        counter--;
                }

                if (maxLen < (end - start)) {
                    maxLen = end - start;
                    head = start;
                }
            }

            cout << "found one: " << s.substr(head, maxLen) << endl;
            return maxLen;
        }

        // Longest Substring without Repeating Characters
        int lengthOfLongestSubstring(string s) {
            int repeat = 0, maxLen = 0, begin = 0, end = 0, head = 0;
            unordered_map<char, int> map;
            int size = s.size();

            while (end < size) {
                if (map[s[end++]]++ > 0)
                    repeat++;

                while (repeat > 0) {
                    if (map[s[begin++]]-- > 1)
                        repeat--;
                }

                if (maxLen < end - begin) {
                    maxLen = end - begin;
                    head = begin;
                }
            }

            cout << "found one: " << s.substr(head, maxLen) << endl;
            return maxLen;
        }
}; // -----  end of class Extension  -----


#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    cout << Solution().minWindow("abcdeffggaggagu", "aeg") << endl;
    cout << "Extension:" << endl;
    cout << Extension().lengthOfLongestSubstringTwoDistinct("abcdeffggaggagu") <<
         endl;
    cout << Extension().lengthOfLongestSubstring("abcdeffggaggagu") << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
