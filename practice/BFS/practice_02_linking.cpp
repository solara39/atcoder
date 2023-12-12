#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int> >;

int main()
{
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	//データ構造
	vector<int> dist(N, -1);
	queue<int> que;

	int count = 0;

	for (int v = 0; v < N; ++v)
	{
		if (dist[v] != -1)
			continue;//既に発見済み
		dist[v] = 0;
		que.push(v);
		while (!que.empty())
		{
			int current = que.front();
			que.pop();
			for (auto nv : G[current])
			{
				if (dist[nv] == -1)
				{
					dist[nv] = dist[current] + 1;
					que.push(nv);
				}
			}
		}
		count++;
	}
	cout << count << endl;
}
