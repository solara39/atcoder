#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int to;
	int weight;
	Edge (int t, int w) : to(t), weight(w) {}
};

using Graph = vector<vector<Edge> >;

int main()
{
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		G[from].push_back(Edge(to, weight));
	}
}
