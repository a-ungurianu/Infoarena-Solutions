#include <fstream>
#include <vector>

using namespace std;

class TrieNode {

public:

    TrieNode() : TrieNode('\0') {}

    TrieNode(char symbol) :
        symbol(symbol),
        count(0),
        childCount(0),
        toDelete(false),
        child(sigma) {}

    // Used iterators instead of strings for efficiency reasons
    void insertWord(string::iterator curr, string::iterator end) {
        if(curr!=end) {
            if(!child[*curr - 'a']) {
                child[*curr - 'a'] = new TrieNode(*curr - 'a');
                childCount++;
            }
            child[*curr - 'a']->insertWord(curr+1,end);
        }
        else
            count++;
    }

    void deleteWord(string::iterator curr, string::iterator end) {
        if(curr!=end) {
            if(child[*curr - 'a']) {
                child[*curr - 'a']->deleteWord(curr+1,end);
                if(child[*curr - 'a']->toDelete) {
                    childCount--;
                    delete child[*curr - 'a'];
                    child[*curr - 'a'] = nullptr;

                }
                if(childCount == 0 && count == 0) {
                    toDelete = true;
                }
            }
        }
        else {
            count--;
            if(childCount==0 && count==0) {
                toDelete = true;
            }
        }
    }

    unsigned findWord(string::iterator curr, string::iterator end) {
        if(curr!=end)
            if(child[*curr - 'a'])
                return child[*curr - 'a']->findWord(curr+1,end);
            else
                return 0;
        else {
            return count;
        }
    }
    unsigned longestPrefix(string::iterator curr, string::iterator end) {
        if(curr!=end && child[*curr - 'a'])
                return 1 + child[*curr - 'a']->longestPrefix(curr+1,end);
        return 0;
    }

private:
    static const unsigned sigma = 'z'-'a'+1;

    unsigned count;
    unsigned childCount;
    char symbol;
    bool toDelete;

    vector<TrieNode *> child;
};


int main() {

    TrieNode trie;
    string s;
    unsigned type;
    ifstream in("trie.in");
    ofstream out("trie.out");
    while(in >> type >> s) {
        switch(type) {
            case 0: {
                trie.insertWord(s.begin(),s.end());
            }break;
            case 1: {
                trie.deleteWord(s.begin(),s.end());
            }break;
            case 2: {
                out << trie.findWord(s.begin(),s.end()) << '\n';
            }break;
            case 3: {
                out << trie.longestPrefix(s.begin(),s.end()) << '\n';
            }break;
        }
    }

    return 0;
}
