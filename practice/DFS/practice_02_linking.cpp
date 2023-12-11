#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int> >;

vector<bool> seen;
void dfs(const Graph &G, int v)
{
	seen[v] = true;

	for (auto next_v : G[v])
	{
		if (seen[next_v])
			continue;
		dfs(G, next_v);
	}
}

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

	int count = 0;
	seen.assign(N, false);
	for (int v = 0; v < N; ++v)
	{
		if (seen[v])// v が探索済みだったらスルー
			continue;
		dfs(G, v);// v が未探索なら v を始点とした DFS 
		++count;
	}
	cout << count << endl;
}
