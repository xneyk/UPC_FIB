// P4
#include <iostream>
#include <vector>
#include <list>

using namespace std;
typedef vector<vector<char> > Map;

struct Pos {
   int i;
   int j;
   Pos() {
      i = 0;
      j = 0;
   }
   Pos(int i, int j) {
      this->i = i;
      this->j = j;
   }
};

bool valid_position(Pos p, const Map &map) {
   return 0 <= p.i && p.i < map.size() && 0 <= p.j && p.j < map[0].size();
}

/**
 * PRE: current is a valid position in map.
*/
void print_paths(Pos current, Pos end, const vector<vector<char> > &map, vector<vector<bool> > &visited, list<char> &path) {
   if (current.i == end.i && current.j == end.j) {
      list<char>::const_iterator it = path.begin();
      while (it != path.end()) { // path finished
         cout << *it;
         ++it;
      }
      cout << endl;
   } else { // end position not reached
      for (int i = -1; i <= 1; ++i) {
         for (int j = -1; j <= 1; ++j) {
            if (i != 0 && j != 0) continue; // diagonal moves not allowed

            Pos neighbour(current.i + i, current.j + j);
            if (valid_position(neighbour, map) && !visited[neighbour.i][neighbour.j]) {
               visited[neighbour.i][neighbour.j] = true;
               path.push_back(map[neighbour.i][neighbour.j]);
               
               print_paths(neighbour, end, map, visited, path);
               
               path.pop_back();
               visited[neighbour.i][neighbour.j] = false;
            }
         }
      }
   }
}

void print_paths(Pos start, Pos end, const vector<vector<char> > &map) {
   int n = map.size();
   int m = 0;
   if (n > 0) m = map[0].size();
 
   if (valid_position(start, map)) {
      list<char> path;
      vector<vector<bool> > visited(n, vector<bool>(m, false));
      path.push_back(map[start.i][start.j]);
      visited[start.i][start.j] = true;

      print_paths(start, end, map, visited, path);
   }
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<char> > map(n, vector<char>(m));

   // read the map;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cin >> map[i][j];
   }

   Pos start, end;
   cin >> start.i >> start.j >> end.i >> end.j;
   print_paths(start, end, map);
}