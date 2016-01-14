/*
 * =====================================================================================
 *
 *       Filename:  min_path_sum.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/12/2015 11:43:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int minPathSum(vector<vector<int> >& grid)
        {
            int m = grid.size();

            if (m == 0)
                return 0;

            int n = grid[0].size();

            if (n == 0)
                return 0;

            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == 0 && j > 0)
                        grid[0][j] += grid[0][j - 1];
                    else if (i > 0 && j == 0)
                        grid[i][0] += grid[i - 1][0];
                    else if (i > 0 && j > 0)
                        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }

            return grid[m - 1][n - 1];
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
main(int argc, char* argv[])
{
    vector<vector<int> > grid;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    grid.push_back(v);
    grid.push_back(v);
    grid.push_back(v);
    grid.push_back(v);
    grid.push_back(v);
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
