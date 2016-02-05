/*
 * =====================================================================================
 *
 *       Filename:  332_reconstruct_itinerary.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/04/16 20:12:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;


/*
 * =====================================================================================
 *        Class:  Solution
 *  Description:
 * =====================================================================================
 */
class Solution {
    public:
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            // 1. init the graph
            for (auto ticket : tickets)
                targets[ticket.first].insert(ticket.second);

            // 2. DFS
            visit("JFK");
            return vector<string>(route.rbegin(), route.rend());
        }

        void visit(string airport) {
            while (targets[airport].size()) {
                string next = *(targets[airport].begin());
                targets[airport].erase(targets[airport].begin());
                visit(next);
            }

            route.push_back(airport);
        }

    private:
        map<string, multiset<string>> targets;
        vector<string> route;
}; /* -----  end of class Solution  ----- */

#include	<stdlib.h>

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    vector<pair<string, string>> tickets;
    tickets.push_back(make_pair("MUC", "LHR"));
    tickets.push_back(make_pair("JFK", "MUC"));
    tickets.push_back(make_pair("SFO", "SJC"));
    tickets.push_back(make_pair("LHR", "SFO"));
    vector<string> res = Solution().findItinerary(tickets);

    for (auto s : res)
        cout << s << " ";

    cout << endl;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

