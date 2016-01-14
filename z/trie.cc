/*
 * =====================================================================================
 *
 *       Filename:  trie.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/29/2015 09:57:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

const int NUM_OF_ALPHABET = 26;

class TrieNode
{
    public:
        // Initialize your data structure here.
        TrieNode() : children(new TrieNode*[NUM_OF_ALPHABET]()), isWord(false)
        {
        }

        TrieNode** children;
        bool isWord;
};

class Trie
{
    public:
        Trie()
        {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word)
        {
            TrieNode* current = root;

            for (unsigned int i = 0; i < word.length(); ++i)
            {
                if (current->children[word[i] - 'a'] == NULL)
                    current->children[word[i] - 'a'] = new TrieNode();

                current = current->children[word[i] - 'a'];
            }

            current->isWord = true;
        }

        // Returns if the word is in the trie.
        bool search(string word)
        {
            TrieNode* current = root;

            for (unsigned int i = 0; i < word.length(); ++i)
            {
                if (current->children[word[i] - 'a'] != NULL)
                    current = current->children[word[i] - 'a'];
                else
                    return false;
            }

            return current->isWord;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix)
        {
            TrieNode* current = root;

            for (unsigned int i = 0; i < prefix.length(); ++i)
            {
                if (current->children[prefix[i] - 'a'] != NULL)
                    current = current->children[prefix[i] - 'a'];
                else
                    return false;
            }

            return true;
        }

    private:
        TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int main(int argc, char* argv[])
{
    Trie trie;
    trie.insert("somethingc");
    bool b = trie.search("something");
    cout << b << endl;
    b = trie.startsWith("somethingcd");
    cout << b << endl;
    trie.insert("something");
    b = trie.search("something");
    cout << b << endl;
    return 0;
}				/* ----------  end of function main  ---------- */
