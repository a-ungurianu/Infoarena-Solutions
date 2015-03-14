#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int x,y;
};

ostream & operator<<(ostream &os, Point p) {
	os << '{' << p.x << ", " << p.y << '}';
	return os;
}

bool operator==(const Point & lhs, const Point & rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}


unsigned n,m;


vector<vector<unsigned>> map;

template<typename T>
void print_vector(ostream &os, vector<T> vec) {
	for(const T& val:vec) {
		os << val << ' ';
	}
	os << '\n';
}

const short dx[] = {-1, 1, 0, 0};
const short dy[] = { 0, 0,-1, 1};

unsigned safest_cell_value;

bool in_bounds(Point p) {
	return 0 <= p.x && p.x < n && 0 <= p.y && p.y < m;
}

const unsigned inf = 1 << 31;

vector<vector<unsigned>> process_dragons(vector<Point> dragons) {
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	vector<vector<unsigned>> distance_to_nearest_dragon(n,vector<unsigned>(m,inf));


	queue<Point> cells_to_process;
	for(Point dragon:dragons) {
		distance_to_nearest_dragon[dragon.x][dragon.y] = 0;
		cells_to_process.push(dragon);
		visited[dragon.x][dragon.y] = true;
	}

	while(!cells_to_process.empty()) {
		Point current_cell = cells_to_process.front();
		for(unsigned k = 0; k < 4; ++k) {
			Point next_cell = current_cell;
			next_cell.x += dx[k];
			next_cell.y += dy[k];
			if( in_bounds(next_cell)) {
				if(!visited[next_cell.x][next_cell.y] && map[next_cell.x][next_cell.y] != -1) {
					visited[next_cell.x][next_cell.y] = true;
					distance_to_nearest_dragon[next_cell.x][next_cell.y] = distance_to_nearest_dragon[current_cell.x][current_cell.y]+1;
					if(distance_to_nearest_dragon[next_cell.x][next_cell.y] != inf)
						safest_cell_value = distance_to_nearest_dragon[next_cell.x][next_cell.y];
					cells_to_process.push(next_cell);
				}
			}
		}
		cells_to_process.pop();
	}
	return distance_to_nearest_dragon;
}

bool check_path(const vector<vector<unsigned>> distance_to_nearest_dragon, Point from, Point to, unsigned safe_limit) {

	vector<vector<bool>> visited(n,vector<bool>(m,false));

	queue<Point> cells_to_process;
	for(cells_to_process.push(from); !cells_to_process.empty(); cells_to_process.pop()) {
		Point current_cell = cells_to_process.front();
		if(distance_to_nearest_dragon[current_cell.x][current_cell.y] != inf && 
		   distance_to_nearest_dragon[current_cell.x][current_cell.y] >= safe_limit) {
		if(current_cell == to) return true;
			for(int k = 0; k < 4; ++k) {
				Point next_cell = current_cell;
				next_cell.x += dx[k];
				next_cell.y += dy[k];
				if(in_bounds(next_cell) && !visited[next_cell.x][next_cell.y]) {
					visited[next_cell.x][next_cell.y] = true;
					cells_to_process.push(next_cell);
				}
			}
		}
	}

	return false;
}

int safest_path(const vector<vector<unsigned>> distance_to_nearest_dragon, Point from, Point to) {
	int st = 0, fn = safest_cell_value;
	int result = -1;
	while(st <= fn) {
		int mid = (st+fn)/2;
		if(check_path(distance_to_nearest_dragon,from,to,mid)) {
			st = mid+1;
			result = max(result,mid);
		}
		else {
			fn = mid-1;
		}
	}
	return result;
}


int main() {

	ifstream in("barbar.in");

	in >> n >> m;

	vector<Point> dragons;

	map.resize(n,vector<unsigned>(m,0));

	Point entry, exit;

	in.ignore();
	
	for(int i = 0; i < n; ++i) {
		string line;
		in >> line;
		for(int j = 0; j < m; ++j) {
			switch(line[j]) {
				case 'D': {
					dragons.push_back({i,j});
				} break;
				
				case '*': {
					map[i][j] = -1;
				} break;
				
				case 'I': {
					entry = {i,j};
				} break;
				
				case 'O': {
					exit = {i,j};
				}
				case '.': break;

				default: throw "Corrupted cell!";
			}
		}
	}

	map.resize(n,vector<unsigned>(m,0));
	vector<vector<unsigned>> distance_to_nearest_dragon = process_dragons(dragons);

	ofstream out("barbar.out");

	// for(int i = 0; i < n; ++i) {
	// 	for(int j = 0; j < m; ++j) {
	// 		if(distance_to_nearest_dragon[i][j] == inf) {
	// 			out << "* ";
	// 		}
	// 		else {
	// 			out << distance_to_nearest_dragon[i][j] << ' ';
	// 		}
	// 	}
	// 	out << '\n';
	// }

	out << safest_path(distance_to_nearest_dragon,entry,exit);

}