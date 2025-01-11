// P5
#include <iostream>
#include <vector>
using namespace std;

struct Pos {
   int i;
   int j;
   Pos(int i, int j) {
      this->i = i;
      this->j = j;
   }
};

bool valid_position(Pos p, const vector<vector<char> > &map) {
   return (0 <= p.i && p.i < map.size()) && (0 <= p.j && p.j < map[0].size());
}

int pick_up_coins(Pos current, vector<vector<char> > &map, vector<vector<bool> > &visited, const char piece) {
   int picked = 0;
   
   if (valid_position(current, map) && !visited[current.i][current.j]) {
      // mark position as visited
      visited[current.i][current.j] = true;
      
      if ('0' <= map[current.i][current.j] && map[current.i][current.j] <= '9') {
         // is a coin ==> pick it up
         picked += map[current.i][current.j] - '0';
         map[current.i][current.j] = '.'; // after picking up coins they disapear.
      } else if (map[current.i][current.j] == 'T') {
         // avoid traps, can't go through it.
         return 0;
      }
      
      if (piece == 'K') { // knight movements
         for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
               // avoid non allowed movements
               if (i == 0 || j == 0 || abs(i) == abs(j)) continue;

               Pos neighbour(current.i + i, current.j + j);
               picked += pick_up_coins(neighbour, map, visited, piece);
            }
         }
      } else if (piece == 'B'){ // bishop movements
         for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
               // avoid non allowd momvents
               if (i == 0 || j == 0) continue;

               Pos neighbour(current.i + i, current.j + j);
               picked += pick_up_coins(neighbour, map, visited, piece);
            }
         }
      }

   }

   return picked;
}

// B --> Bishop
// K --> Knight
// T --> Trap
int pick_up_coins(vector<vector<char> > &map, int n,  int m) {
   int coins = 0;
   vector<vector<bool> > visited_by_knights(n, vector<bool>(m, false));
   vector<vector<bool> > visited_by_bishops(n, vector<bool>(m, false));
   
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {

         if (map[i][j] == 'K') {
            Pos start(i, j);
            coins += pick_up_coins(start, map, visited_by_knights, map[i][j]);
         } else if (map[i][j] == 'B') {
            Pos start(i, j);
            coins += pick_up_coins(start, map, visited_by_bishops, map[i][j]);
         }
      }
   }

   return coins;
}

int main() {
   int n, m;
   while (cin >> n >> m) {
      vector<vector<char> > map(n, vector<char>(m));

      // read map
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) cin >> map[i][j];
      }

      cout << pick_up_coins(map, n, m) << endl;
   }
}