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

int pick_up_coins(Pos current, const vector<vector<char> > &map, vector<vector<bool> > &visited) {
   int picked = 0;
   if (valid_position(current, map)) {
      
      // is a coin ==> pick it up
      if ('0' <= map[current.i][current.j] && map[current.i][current.j] <= '9') {
         picked += map[current.i][current.j] - '0';
      }
   }
}

// B --> bishop
// K --> Knight
// T --> Trap
int pick_up_coins(const vector<vector<char> > &map) {
   int n = map.size();
   int m = map[0].size();
   
   int coins = 0;

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (map[i][j] == 'K' || map[i][j] == 'B') {
            Pos start(i, j);
            vector<vector<bool> > visited(n, vector<bool>(m, false));
            coins += pick_up_coins(start, map, visited);
         }
      }
   }
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<char> > map(n, vector<char>(m));

   // read map
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cin >> map[i][j];
   }

   pick_up_coins(map);
}