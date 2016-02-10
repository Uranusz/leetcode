// =====================================================================================
//
//       Filename:  146_LRU_cache.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/06/2016 10:14:29 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// =====================================================================================
//        Class:  LRUCache
//  Description:
// =====================================================================================
class LRUCache {
    public:
        LRUCache(int capacity) : _capacity(capacity) {}

        int get(int key) {
            auto found_iter = _map.find(key);

            if (found_iter == _map.end())
                return -1;

            _list.splice(_list.begin(), _list, found_iter->second);
            return found_iter->second->second;
        }

        void set(int key, int value) {
            auto found_iter = _map.find(key);

            if (found_iter != _map.end()) {
                _list.splice(_list.begin(), _list, found_iter->second);
                found_iter->second->second = value;
                return;
            }

            if (_map.size() == _capacity) {
                int key_to_del = _list.back().first;
                _list.pop_back();
                _map.erase(key_to_del);
            }

            _list.emplace_front(key, value);
            _map[key] = _list.begin();
        }

    private:
        size_t _capacity;
        list<pair<int, int>> _list;
        unordered_map<int, list<pair<int, int>>::iterator> _map;

}; // -----  end of class LRUCache  -----

#include	<stdlib.h>

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main(int argc, char* argv[]) {
    LRUCache(10).get(1);
    return EXIT_SUCCESS;
}				// ----------  end of function main  ----------
