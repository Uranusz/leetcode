/*
 * =====================================================================================
 *
 *       Filename:  happy_number.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/06/2015 08:20:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<vector>
#include	<string>
#include	<stdlib.h>

using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            vector<int> v;

            while (n) {
                int digit = n % 10;

                if (digit != 0)
                    v.push_back(digit);

                n = n / 10;
            }

            if (v.size() == 1) {
                if (v[0] == 1 || v[0] == 7) {
                    cout << "!!!" << endl;
                    return true;
                } else {
                    cout << "???" << endl;
                    return false;
                }
            } else {
                int new_num = 0;

                for (unsigned int i = 0; i < v.size(); ++i)
                    new_num += v[i] * v[i];

                cout << "new_num: " << new_num << ", continue computing..." << endl;
                return isHappy(new_num);
            }
        }
};


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    int num = 0;

    //cout << argc << endl;
    if (argc != 2) {
        cout << "please enter a number..." << endl;
        return -1;
    } else
        num = atoi(argv[1]);

    cout << "num: " << num << endl;
    Solution s;

    if (s.isHappy(num))
        cout << "happy!" << endl;
    else
        cout << "sad..." << endl;

    return 0;
}				/* ----------  end of function main  ---------- */
