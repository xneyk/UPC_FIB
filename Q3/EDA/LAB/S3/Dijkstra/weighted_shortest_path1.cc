#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int infinite = numeric_limits<int>::infinity();

struct Arc {
   int node;
   int weight;
};

typedef vector<vector<Arc> > Graf;

int dijkstra(Graf &G, int u, int v) {
   vector<int> distance(G.size());
   // priority_queue<
   for (int i = 0; i < distance.size(); ++i) distance[i] = infinite;
   distance[u] = 0; // distance s to s is 0.

}

int main() {
   int n, m;
   cin >> n >> m;
   Graf graf(n);

   for (int i = 0; i < m; ++i) { // cada aresta -> al node del que surten.
      int from_node;
      Arc arc;
      cin >> from_node >> arc.node >> arc.weight;
      graf[from_node].push_back(arc);
   }

   // for (int i = 0; i < n; ++i) {
   //    cout << i << ": ";
   //    for (int j = 0; j < graf[i].size(); ++j) {
   //       cout << '(' << graf[i][j].node << ' ' << graf[i][j].weight << ')';
   //    }
   //    cout << endl;
   // }
}