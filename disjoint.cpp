#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("disjoint.in");
ofstream out("disjoint.out");

struct node {
	size_t parent,rank;
};

vector<node> forest;

void InitForest(size_t n) {
	forest.resize(n);
	for(size_t i = 0; i < n; ++i) {
		forest[i].parent = i;
		forest[i].rank = 0;
	}
}

size_t FindRep(size_t i) {
	if(forest[i].parent != i) {
		forest[i].parent = FindRep(forest[i].parent);
	}
	return forest[i].parent;
}
void UniteSets(size_t s1, size_t s2) {
	size_t repS1 = FindRep(s1);
	size_t repS2 = FindRep(s2);
	if(forest[repS1].rank < forest[repS2].rank) {
		forest[repS1].parent = repS2;
	}
	else if(forest[repS1].rank < forest[repS2].rank) {
		forest[repS2].parent = repS1;
	}
	else {
		forest[repS2].parent = repS1;
		forest[repS1].rank++;
	}
}

int main() {
	size_t n,m;
	in >> n >> m;
	InitForest(n);
	for(size_t i = 0; i < m; ++i) {
		size_t type,set1,set2;
		in >> type >> set1 >> set2;
		switch(type) {
			case 1:
				UniteSets(set1,set2);
				break;
			case 2:
				if(FindRep(set1)==FindRep(set2))
					out << "DA\n";
				else
					out << "NU\n";
		}
	}
	return 0;
}
