#include <fstream>
#include <vector>

using namespace std;

ifstream in("sumfact.in");
ofstream out("sumfact.out");

vector<unsigned> facts;

void InitFacts(unsigned n) {
    facts.push_back(1);
    size_t i = 2;
    while(facts.back() < n)
        facts.push_back(facts.back()*i++);
    if(facts.back()!=n)facts.pop_back();
}

vector<unsigned> FactDesc(unsigned n) {
    vector<unsigned> sol;
    sol.resize(facts.size());
    for(size_t i = sol.size(); i > 0; --i) {
        unsigned curCnt = 0;
        while(n>=facts[i-1]){
            n-=facts[i-1];
            curCnt++;
        }
        sol[i-1]=curCnt;
    }
    return sol;
}

int main() {
    unsigned n;
    in >> n;

    InitFacts(n);
    vector<unsigned> desc = FactDesc(n);

    out << desc.size() << '\n';
    for(size_t i = 0; i < desc.size(); ++i) {
        out << desc[i] << '\n';
    }

    return 0;
}
