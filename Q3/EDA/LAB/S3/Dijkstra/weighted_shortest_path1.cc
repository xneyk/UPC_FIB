#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int infinite = numeric_limits<int>::max();


struct Arc {
	int node;
	int weight;
	// Per a poder ser utilitzat per std::greater a la classe prority_queue.
   Arc() {}
	Arc(int n, int w) {
		node = n;
		weight = w;
	}
	bool operator>(const Arc &a) const {
		return weight > a.weight;
	}
};

typedef vector<vector<Arc> > Graf;

void dijkstra(const Graf &graf, int initial_node, vector<int> &distance, vector<int> &previous) {
	int n = graf.size();
	distance = vector<int>(n, infinite); // Totes les distancies a infinit
	distance[initial_node] = 0;          // menys el node inicial.
	vector<bool> visited(n, false); // nodes visitats
	previous = vector<int>(n, -1); // per a reconstruir el camí
	priority_queue<Arc, vector<Arc>, greater<Arc> > Q;
	Q.push(Arc(initial_node, 0)); // afegim el node inicial

	while (not Q.empty()) {
		int current_node = Q.top().node;
		Q.pop();
		if (not visited[current_node]) {
				visited[current_node] = true;

				int neighbours = graf[current_node].size();
				for (int i = 0; i < neighbours; ++i) {
					Arc neighbour = graf[current_node][i];
					// Si pasar pel node actual fa que el cami sigui més curt
					if (distance[current_node] + neighbour.weight < distance[neighbour.node]) {
						// Actualitzem distancia i node anterior
						distance[neighbour.node] = distance[current_node] + neighbour.weight;
						previous[neighbour.node] = current_node;
						// Afegim candidat a seguen node pel que trobar camins minims.
						Q.push(Arc(neighbour.node, distance[neighbour.node]));
					}
				}
		}
	}
}

int main() {
   int n, m;
   while (cin >> n >> m ) {
      Graf graf(n);

      for (int i = 0; i < m; ++i) { // cada aresta -> al node del que surten.
         int from_node;
         Arc arc;
         cin >> from_node >> arc.node >> arc.weight;
         graf[from_node].push_back(arc);
      }

      vector<int> distance;
      vector<int> previous;
      int x, y;
      cin >> x >> y;
      dijkstra(graf, x, distance, previous);
      distance[y] != infinite ? cout << distance[y] : cout << "no path from " << x << " to " << y;
      cout << endl;
   }
}