#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int> >;

vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0)
{
	color[v] = cur;

	for (auto next_v : G[v])
	{
		if (color[next_v] != -1)// 隣接頂点がすでに色確定
		{
			if (color[next_v] == cur)
				return false;
			continue;
		}
		// 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
		if (!dfs(G, next_v, 1 - cur))
			return false;
	}
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int s, t;
	cin >> s >> t;

	Graph G(N);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// 探索
	color.assign(N, -1);
	bool is_bipartite = true;
	for (int v = 0; v < N; ++v)
	{
		if (color[v] != -1)
			continue;
		if (!dfs(G, v))
			is_bipartite = false;
	}
	if (is_bipartite) 
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
}
