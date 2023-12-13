#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_V 1000
#define INF 10000000

struct Edge{
	int from;
	int to;
	int cost;
	Edge(int f, int t, int w) : from(f), to(t), cost(w) {}
};

int main()
{
	int N, M;
	cin >> N >> M;

	int s, g;
	cin >> s >> g;

	vector<int> d;
	vector<Edge> edges;
	d.assign(N, INF);
	d[s] = 0;

	for (int i = 0; i < M; ++i)
	{
		int from, to, w;
		cin >> from >> to >> w;
		edges.push_back(Edge(from, to, w));
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < (int)edges.size(); j++)
		{
			struct Edge current = edges[j];
			if (d[current.to] > d[current.from] + current.cost)
			{
				d[current.to] = d[current.from] + current.cost;
				if (i == N - 1)
				{
					cout << "negative loop" << endl;
					break;
				}
			}
		}
	}
	cout << d[g] << endl;
}
