// =====================================================================================
//
//       Filename:  122_best_time_to_buy_and_sell_stock.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/18/2016 10:21:13 PM
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
        int maxProfit(vector<int>& prices) {
            if (prices.size() <= 1)
                return 0;

            // buy at valley, sell at peak
            int profit = 0;

            for (unsigned int i = 0; i < prices.size() - 1; ++i) {
                if (prices[i + 1] > prices[i])
                    profit += prices[i + 1] - prices[i];
            }

            return profit;
        }
}; // -----  end of class Solution  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    vector<int> v({2, 3, 1, 4});
    cout << Solution().maxProfit(v) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
