#include <fstream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000];

struct Pos {
	unsigned l,c;
};

unsigned n,m;

bool in_bounds(Pos p) {
	return p.l < n && p.c < m;
}

bool visited[1000][1000];

void check(queue<Pos> &next_process, Pos here, char &min_c) {
	Pos next{here.l,here.c+1};
	if(in_bounds(next)) {
		if(map[next.l][next.c] < min_c) {
			min_c = map[next.l][next.c];
			next_process = queue<Pos>();
			next_process.push(next);
			visited[next.l][next.c] = true;
		}
		else if(map[next.l][next.c] == min_c && !visited[next.l][next.c]) {
			next_process.push(next);
			visited[next.l][next.c] = true;
		}
	}

	next = {here.l+1,here.c};

	if(in_bounds(next)) {
		if(map[next.l][next.c] < min_c) {
			min_c = map[next.l][next.c];
			next_process = queue<Pos>();
			next_process.push(next);
			visited[next.l][next.c] = true;
		}
		else if(map[next.l][next.c] == min_c) {
			next_process.push(next);
			visited[next.l][next.c] = true;
		}
	}
}

int main() {

	ifstream in("drum6.in");
	in >> n >> m;

	in.ignore();
	for(int i = 0; i < n; ++i) {
		in >> map[i];
	}

	queue<Pos> process;
	queue<Pos> next_process;

	process.push({0,0});

	string solution;
	solution.push_back(map[0][0]);

	while(solution.size() < n+m-1) {
		char min_c = 'z' + 2;
		while(!process.empty()) {
			Pos here = process.front();
			process.pop();
			check(next_process,here,min_c);
		}
		solution.push_back(min_c);
		process = next_process;
		next_process = queue<Pos>();
	}

	ofstream out("drum6.out");
	out << solution << '\n';

	return 0;
}