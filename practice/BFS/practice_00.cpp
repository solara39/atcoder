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

	//初期化
	dist[0] = 0;
	que.push(0);

	//BFS開始
	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (int nv : G[v])
		{
			if (dist[nv] != -1)
				continue;//既に発見済み
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}

	for (int v = 0; v < N; v++)
		cout << v << ":" << dist[v] << endl;
}
