// =====================================================================================
//
//       Filename:  249_group_shifted_strings.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/12/2016 09:06:00 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        vector<vector<string>> groupStrings(vector<string>& strings) {
            vector<vector<string>> res;
            unordered_map<string, vector<string>> map;

            for (auto s : strings) {
                stringstream ss;
                int diff = s[0] - 'a';

                for (auto c : s) {
                    auto tmp = c - diff;
                    tmp = tmp >= 0 ? tmp : tmp + 26;
                    ss << tmp;
                }

                map[ss.str()].push_back(s);
            }

            for (auto iter : map) {
                res.push_back(iter.second);
                sort(res.back().begin(), res.back().end());
            }

            for (auto v : res) {
                for (auto s : v)
                    cout << s << " ";

                cout << endl;
            }

            return res;
        }
}; // -----  end of class Solution  -----


#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int main(int argc, char* argv[]) {
    vector<string> v({"xyz", "abc", "bcd", "dtr", "a", "z", "rt", "yu"});
    Solution().groupStrings(v);
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
