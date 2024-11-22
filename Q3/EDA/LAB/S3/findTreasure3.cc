#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> nodes;
typedef vector<vector<char> > map_graf;
typedef vector<vector<bool> > visited_matrix;

struct coord_2d {
   int width;
   int height;
};

void findTreasure(
      const map_graf &map,
      const coord_2d &map_size,
      coord_2d curr_pos,
      visited_matrix &visited,
      int &n) {
   if (!visited[curr_pos.height - 1][curr_pos.width - 1] && map[curr_pos.height - 1][curr_pos.width - 1] != 'X') {
      visited[curr_pos.height - 1][curr_pos.width - 1] = true; // you're here
      if (map[curr_pos.height - 1][curr_pos.width - 1] == 't') ++n;
      for (int i = -1; i <= 1; ++i) {
         for (int j = -1; j <= 1; ++j) {
            if (i == 0 or j == 0) { // you cannot move in diagonal.
               coord_2d next_pos;
               next_pos.height = curr_pos.height + i;
               next_pos.width = curr_pos.width + j;
               bool y_limits = 1 <= next_pos.height and next_pos.height <= map_size.height;
               bool x_limits = 1 <= next_pos.width and next_pos.width <= map_size.width;
               if (y_limits && x_limits) {
                  findTreasure(map, map_size, next_pos, visited, n);
               }
            }
         }
      }
   }
}

int findTreasure(const map_graf &map, const coord_2d &map_size, coord_2d ini_pos) {
   vector<vector<bool> > visited(map_size.height, vector<bool>(map_size.width, false));
   int n = 0;
   findTreasure(map, map_size, ini_pos, visited, n);
   return n;
}

int main() {
   coord_2d map_size; // map is square from (0,0) to (w, h)
   cin >> map_size.height >> map_size.width;
   map_graf map(map_size.height, nodes(map_size.width));

   // read game map as a graf.
   for (int i = 0; i < map_size.height; ++i) {
      for (int j = 0; j < map_size.width; ++j) cin >> map[i][j];
   }

   coord_2d ini_pos;
   cin >> ini_pos.height >> ini_pos.width;
   cout << findTreasure(map, map_size, ini_pos) << endl;
}