#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int> >;

//深さ優先探索
vector<bool> seen;
vector<int> first_order;//行きがけ順
vector<int> last_order;//帰りがけ順

void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr)
{
	first_order[v] = first_ptr++;
	seen[v] = true;

	// v から行ける各頂点 next_v について
	for (auto next_v : G[v])
	{
		if (seen[next_v])
			continue;// next_v が探索済だったらスルー
		dfs(G, next_v, first_ptr, last_ptr);// 再帰的に探索
	}
	last_order[v] = last_ptr++;
}

int main()
{
	int N, M;
	cin >> N >> M;

	// グラフ入力受取 (ここでは無向グラフを想定)
	Graph G(N);
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// 頂点 0 をスタートとした探索
	seen.assign(N, false);// 全頂点を「未訪問」に初期化
	first_order.resize(N);
	last_order.resize(N);
	int first_ptr, last_ptr;
	first_ptr = last_ptr = 0;
	dfs(G, 0, first_ptr, last_ptr);

	for (int v = 0; v < N; ++v)
		cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}
