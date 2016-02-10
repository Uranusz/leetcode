// =====================================================================================
//
//       Filename:  331_verify_preorder_serialization_of_bst.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/06/2016 08:33:28 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool isValidSerialization(string preorder) {
            vector<string> list = split(preorder, ',');
            int leaves = 0, nonleaves = 0;
            unsigned int i = 0;

            for (; i < list.size(); i++) {
                if (list[i] != "#")
                    nonleaves++;
                else
                    leaves++;

                if (leaves >= nonleaves + 1 && i != list.size() - 1)
                    return false;
            }

            return nonleaves + 1 == leaves;
        }

        vector<string> split(string& s, char delim) {
            vector<string> elems;
            stringstream ss(s);
            string item;

            while (getline(ss, item, delim))
                elems.push_back(item);

            return elems;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    string s = "9,#,92,#,#";
    bool b = Solution().isValidSerialization(s);
    cout << b << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

