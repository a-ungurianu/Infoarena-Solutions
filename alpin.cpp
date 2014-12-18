#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("alpin.in");
ofstream out("alpin.out");

struct Path {
	Path(int line,int column, unsigned length) :
        line(line),
        column(column),
        length(length) {}

    int line;        // The line of the end of the path
    int column;      // The column of the end of the path
	unsigned length; // The length of the path that ends in the point above
};

template <typename T>
using Matrix = vector<vector<T>>;

unsigned mapSize;

Matrix<Path> bestPathTo;

Matrix<unsigned> mountainMap;

bool InBounds(int i, int j) {
	return !((i < 0 || i >= mapSize) ||
             (j < 0 || j >= mapSize));
}

// Possible neighbour deltas for a given positions
const int dl[] = {-1, 0, 1, 0};
const int dc[] = { 0, 1, 0,-1};

Path LongestPathTo(int i, int j) {
	if(bestPathTo[i][j].length > 0) return bestPathTo[i][j];

	Path maxPath(i,j,0);

	for(int k = 0; k < 4; ++k) {
		if(InBounds(i + dl[k], j + dc[k]) && // Are we still in the map?
           mountainMap[i + dl[k]][j + dc[k]] < mountainMap[i][j]) // Are we getting to a lower place?
        {
			Path vecPath = LongestPathTo(i + dl[k], j + dc[k]);
			if(vecPath.length + 1 > maxPath.length) {
				maxPath = Path(i + dl[k], j + dc[k], vecPath.length+1);
			}
		}
	}
	bestPathTo[i][j] = maxPath;
	return bestPathTo[i][j];
}

void printPath(Path path) {
	Path parent = bestPathTo[path.line][path.column];
	if(parent.column == path.column && parent.line == path.line) // Is it a start node?
    {
		out << path.line + 1 << ' ' << path.column + 1 << '\n';
	}
	else {
		printPath(parent);
		out << path.line + 1 << ' ' << path.column + 1 << '\n';
	}
}

int main() {
	in >> mapSize;

    bestPathTo.resize(mapSize);
    mountainMap.resize(mapSize);

    // Resize line by line
    for(unsigned i = 0; i < mapSize; ++i) {
        bestPathTo[i].resize(mapSize,Path(0,0,0));
        mountainMap[i].resize(mapSize,0);
    }

    for(unsigned i = 0; i < mapSize; ++i) {
        for(unsigned j = 0; j < mapSize; ++j) {
            in >> mountainMap[i][j];
        }
    }

	Path longestPath(0,0,0);

	for(int i = 0; i < mapSize; ++i) {
		for(int j = 0; j < mapSize; ++j) {
            Path pathToHere = LongestPathTo(i,j);
			if(pathToHere.length + 1 > longestPath.length) {
                longestPath = Path(i,j,pathToHere.length+1);
            }
		}
	}
	out << longestPath.length << '\n';
	printPath(longestPath);
}
