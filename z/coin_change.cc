/*
 * =====================================================================================
 *
 *       Filename:  coin_change.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/29/2015 09:02:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiahao Zhu
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * =====================================================================================
 *        Class:  Solution
 *  Description:
 * =====================================================================================
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, amount + 1);
        table[0] = 0;

        for(int i = 1; i <= amount; ++i)
            for(unsigned int j = 0; j < coins.size(); ++j)
                if (coins[j] <= i)
                    table[i] = min(table[i], table[i - coins[j]] + 1);

        return table[amount] > amount ? -1 : table[amount];
    }

}; /* -----  end of class Solution  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
    Solution s;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    cout << "res: " << s.coinChange(v, 14) << endl;

    return 0;
}				/* ----------  end of function main  ---------- */
