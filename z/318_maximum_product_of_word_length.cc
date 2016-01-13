// =====================================================================================
//
//       Filename:  318_maximum_product_of_word_length.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/06/2016 10:20:31 PM
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
    int maxProduct(vector<string>& words) {
        typedef unsigned int uint;
        uint total = words.size();

        vector<int> masks(total, 0);

        // 1. generate mask for each word
        for(uint i = 0; i < total; ++i)
            for(uint j = 0; j < words[i].length(); ++j)
                masks[i] |= 1 << (words[i][j] - 'a');

        unsigned long int res = 0;
        for(uint i = 0; i < total; ++i)
            for(uint j = i+1; j < total; ++j)
                if((masks[i] & masks[j]) == 0)
                    res = max(res, words[i].length() * words[j].length());

        return res;
    }
};

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main ( int argc, char *argv[] ) {
    vector<string> words;
    words.push_back("ab");
    words.push_back("abc");
    words.push_back("abd");
    words.push_back("es");

    cout << Solution().maxProduct(words) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
