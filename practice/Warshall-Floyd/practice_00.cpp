#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
	int V, E;
	cin >> V >> E;

	vector<vector<int> > dist(V, vector<int>(V, INF));

	for (int i = 0; i < V; i++)
		dist[i][i] = 0;
	
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;
	}

	for (int k = 0; k < V; ++k) //経由
		for (int i = 0; i < V; ++i) //始点
			for (int j = 0; j < V; ++j) //終点
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	bool has_neg_cycle = false;
	for (int i = 0; i < V; ++i)
	{
		if (dist[i][i] < 0)
		{
			has_neg_cycle = true;
			break;
		}
	}

	if (has_neg_cycle)
		cout << "negative cycle" << endl;
	else
	{
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				if (dist[i][j] == INF)
					cout << "INF ";
				else
					cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
