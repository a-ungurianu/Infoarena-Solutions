#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("beep.in");
    string bad;
    in >> bad;

    ofstream out("beep.out");
    string s;
    while(in >> s) {
        if(s==bad) out << "beep ";
        else out << s << ' ';
    }
}
