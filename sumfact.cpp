#include <fstream>
#include <vector>

using namespace std;

ifstream in("sumfact.in");
ofstream out("sumfact.out");

vector<unsigned long long> facts;

void InitFacts(unsigned long long n) {
    facts.push_back(1);
    size_t i = 2;
    while(facts.back() < n)
        facts.push_back(facts.back()*i++);
    if(facts.back()!=n)facts.pop_back();
}

vector<unsigned long long> FactDesc(unsigned long long n) {
    vector<unsigned long long> sol;
    sol.resize(facts.size());
    for(int i = sol.size()-1; i >= 0; --i) {
        unsigned long long curCnt = 0;
        while(n>=facts[i]){
            n-=facts[i];
            curCnt++;
        }
        sol[i]=curCnt;
    }
    return sol;
}

int main() {
    unsigned long long n;
    in >> n;

    InitFacts(n);
    vector<unsigned long long> desc = FactDesc(n);

    out << desc.size() << '\n';
    for(size_t i = 0; i < desc.size(); ++i) {
        out << desc[i] << '\n';
    }

    return 0;
}
