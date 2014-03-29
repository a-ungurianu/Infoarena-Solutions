#include <fstream>

using namespace std;

struct TrieNode {
    unsigned cnt,nrSons;
    char c;
    bool toDelete;
    TrieNode *chd['z'-'a'+1];

    TrieNode() {
        cnt = nrSons = 0;
        toDelete = false;
        for(size_t i = 0; i < 'z'-'a'+1; ++i)
            chd[i] = nullptr;
    }
    TrieNode(char c) {
        this->c = c;
        cnt = nrSons = 0;
        toDelete = false;
        for(size_t i = 0; i < 'z'-'a'+1; ++i)
            chd[i] = nullptr;
    }
    void insertWord(string::iterator c, string::iterator fn) {
        if(c!=fn) {
            if(!chd[*c-'a']) {
                chd[*c-'a'] = new TrieNode(*c);
                nrSons++;
            }
            chd[*c-'a']->insertWord(c+1,fn);
        }
        else
            cnt++;
    }

    void deleteWord(string::iterator c, string::iterator fn) {
        if(c!=fn) {
            if(chd[*c-'a']) {
                chd[*c-'a']->deleteWord(c+1,fn);
                if(chd[*c-'a']->toDelete) {
                    nrSons--;
                    delete chd[*c-'a'];
                    chd[*c-'a'] = nullptr;

                }
                if(nrSons == 0 && cnt == 0) {
                    toDelete = true;
                }
            }
        }
        else {
            cnt--;
            if(nrSons==0 && cnt==0) {
                toDelete = true;
            }
        }
    }

    unsigned findWord(string::iterator c, string::iterator fn) {
        if(c!=fn)
            if(chd[*c-'a'])
                return chd[*c-'a']->findWord(c+1,fn);
            else
                return 0;
        else {
            return cnt;
        }
    }
    unsigned longestPrefix(string::iterator c, string::iterator fn) {
        if(c!=fn && chd[*c-'a'])
                return 1 + chd[*c-'a']->longestPrefix(c+1,fn);
        return 0;
    }
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
