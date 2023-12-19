#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int u, v, w;
	Edge(int u, int v, int w) : u(u), v(v), w(w){}
};

class UnionFind{
	vector<int> parent;
public:
	UnionFind(int n) : parent(n){
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x)
			return x;
		else
			return parent[x] = find(parent[x]);
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x != y)
			parent[x] = y;
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};

int Kruskal(vector<Edge> &edges, int V)
{
	int total_weight = 0;
	UnionFind uf(V);

	sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
	{
		return a.w < b.w;
	});

	for (Edge &e : edges) {
        	if (!uf.same(e.u, e.v)) {
            		uf.unite(e.u, e.v);
            	total_weight += e.w;
		}
	}
	return total_weight;
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<Edge> edges;
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}

	cout << "Total weight of MST: " << Kruskal(edges, V) << endl;

	return 0;
}
