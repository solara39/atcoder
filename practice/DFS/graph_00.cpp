#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

int main()
{
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		// 無向グラフの場合は以下を追加
		// G[b].push_back(a);
	}
}
