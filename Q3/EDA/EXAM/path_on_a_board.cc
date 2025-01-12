// X13208
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Arc {
   int cost;
   int i;
   int j;
   bool operator>(const Arc &a) const {
      return cost > a.cost;
   }
};

const int INF = numeric_limits<int>::max();

int cheapest_cost(int n, vector<vector<int> > M) {
   int current_minimum_border = INF;
   Arc start;
   start.i = start.j = n/2; // central point.
   start.cost = M[start.i][start.j];

   vector<vector<bool> > visited(n, vector<bool>(n, false));

   vector<vector<int> > cost(n, vector<int>(n, INF));
   cost[start.i][start.j] = start.cost;

   priority_queue<Arc, vector<Arc>, greater<Arc>> Q;
   
   Q.push(start);
   while (!Q.empty()) {
      Arc current = Q.top();
      Q.pop();

      // if not visited
      if (!visited[current.i][current.j]) {
         visited[current.i][current.j] = true;
         // for each neighbour
         for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
               // diagonal movements not allowed.
               if (i != 0 && j != 0) continue;
               // if valid position
               Arc neighbour;
               neighbour.i = current.i + i;
               neighbour.j = current.j + j;
               if (0 <= neighbour.i && neighbour.i < n && 0 <= neighbour.j && neighbour.j < n) {
                  
                  neighbour.cost = M[neighbour.i][neighbour.j];
                  if (cost[neighbour.i][neighbour.j] > cost[current.i][current.j] + neighbour.cost) {
                     cost[neighbour.i][neighbour.j] = cost[current.i][current.j] + neighbour.cost;
                     neighbour.cost = cost[neighbour.i][neighbour.j];
                     Q.push(neighbour);
                  }
               }
            }
         }

         // if current arc gives us to a border
         if (current.i == 0 || current.i == n-1 || current.j == 0 || current.j == n-1) {
            current_minimum_border = min(cost[current.i][current.j], current_minimum_border);
         }
      }

   }

   return current_minimum_border;
}

int main() {
   int n;
   while (cin >> n) {
      // create and read matrix
      vector<vector<int> > M(n, vector<int>(n));
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) cin >> M[i][j];
      }

      cout << cheapest_cost(n, M) << endl;
   }
}