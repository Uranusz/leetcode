/*
 * =====================================================================================
 *
 *       Filename:  repeated_dna_seq.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/12/2015 09:24:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            vector<string> v;

            if (s.size() <= 10)
                return v;

            /*
             * use hash table to speed-up
             */
            char hash_table[0x100000] = {0};
            int hash_value = 0;

            for (int i = 0; i < 9; ++i)
                hash_value = hash_value << 2 | (s[i] - 'A' + 1) % 5;

            for (unsigned int i = 9; i < s.size(); ++i) {
                if (hash_table[hash_value = (hash_value << 2 | (s[i] - 'A' + 1) % 5) &
                                            0xfffff]++ == 1)
                    v.push_back(s.substr(i - 9, 10));
            }

            return v;
        }

};


#include	<stdlib.h>

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    Solution s;
    vector<string> v =
        s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCAAAAAGGGGGAAAAAGGGGGTTT");
    cout << v.size() << endl;

    for (unsigned int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;

    return 0;
}				/* ----------  end of function main  ---------- */


