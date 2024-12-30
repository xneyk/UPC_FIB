// P1
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Pos {
   int r;
   int c;
   Pos() {
      r = 0;
      c = 0;
   }
   Pos(int r, int c) {
      this->r = r;
      this->c = c;
   }
};

bool valid_position(int i, int j, int n, int m) {
   return (0 <= i && i < n) && (0 <= j && j < m);
}

/**
 * @param r initial row (starting at 0)
 * @param c initial column (starting at 0)
 * @param map n*m character matrix.
*/
int max_distance(int r, int c, vector<vector<char> > &map) {
   int n = map.size(); // rows
   int m = map[0].size(); // columns
   queue<Pos> Q;
   // Nodes with INF distance mean it has not been visited yet.
   const int INF = numeric_limits<int>::max();
   vector<vector<int> > distance(n, vector<int>(m, INF));
   
   int MAX_DISTANCE = -1;
   Q.push(Pos(r, c)); // push starting position.
   distance[r][c] = 0;

   while (!Q.empty()) {
      Pos current = Q.front();
      Q.pop();

      // Treat current node...
      if (map[current.r][current.c] == 't') {
         if (MAX_DISTANCE < distance[current.r][current.c]) {
            // New further treasure reached.
            MAX_DISTANCE = distance[current.r][current.c];
         }
      }

      // Add neighbours
      for (int i = -1; i <= 1; ++i) {
         for (int j = -1; j <= 1; ++j) {
            // Diagonal movements not allowed and it need to be valid positions.
            if ((i == 0 || j == 0) && valid_position(current.r + i, current.c + j, n, m)) {
               Pos neighbour(current.r + i, current.c + j);
               // if valid node ('.' or 't') and not visited yet add it to queue.
               if (map[neighbour.r][neighbour.c] != 'X' && distance[neighbour.r][neighbour.c] == INF) {
                  distance[neighbour.r][neighbour.c] = distance[current.r][current.c] + 1;
                  Q.push(neighbour);
               }
            }
         }
      }
   }

   return MAX_DISTANCE;
}

void read_map(int r, int c, vector<vector<char> > &map) {
   for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) cin >> map[i][j];
   }
}

int main() {
   int r, c;
   cin >> r >> c;
   vector<vector<char> > map(r, vector<char>(c)); // create map[r][c];
   read_map(r, c, map);

   // read initial position coordinates
   cin >> r >> c;
   int distance = max_distance(r - 1, c - 1, map);
   if (distance > -1)  cout << "maximum distance: " << distance << endl;
   else cout << "no treasure can be reached" << endl;
}