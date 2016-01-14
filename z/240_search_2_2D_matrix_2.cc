// =====================================================================================
//
//       Filename:  240_search_2_2D_matrix_2.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/09/2016 10:55:22 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <limits>

using namespace std;


// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target)
        {
            int rowCount = matrix.size();
            int colCount = matrix[0].size();

            for (int i = 0, j = colCount - 1; i < rowCount && j >= 0;)
            {
                if (target == matrix[i][j])
                    return true;
                else if (target < matrix[i][j])
                    j--;
                else if (target > matrix[i][j])
                    i++;
            }

            return false;
        }


}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[])
{
    vector<vector<int>> v;
    vector<int> v1, v2, v3, v4;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(7);
    v1.push_back(11);
    v1.push_back(15);
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(8);
    v2.push_back(12);
    v2.push_back(19);
    v3.push_back(3);
    v3.push_back(6);
    v3.push_back(9);
    v3.push_back(16);
    v3.push_back(22);
    v4.push_back(10);
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(17);
    v4.push_back(24);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    cout << endl;
    //cout << Solution().searchMatrix(v, 50) << endl;
    cout << Solution().searchMatrix(v, 6) << endl;
    cout << Solution().searchMatrix(v, 30) << endl;
    //cout << Solution().searchMatrix(v, 1) << endl;
    //cout << Solution().searchMatrix(v, 18) << endl;
    //cout << Solution().searchMatrix(v, 5) << endl;
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
