#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W;
vector <string> field;

bool seen[510][510];
void dfs(int h, int w)
{
	seen[h][w] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int nh = h + dx[dir];
		int nw = w + dy[dir];

		if (nh < 0 || nw < 0 || nh >= H || nw >= W)
			continue;
		if (field[nh][nw] == '#')
			continue;
		if (seen[nh][nw])
			continue;

		dfs(nh, nw);
	}
}

int main()
{
	cin >> H >> W;
	field.resize(H);

	for (int i = 0; i < H; ++i)
		cin >> field[i];
	int sh, sw, gh, gw;
	for (int h = 0; h < H; ++h)
	{
		for (int w = 0; w < W; ++w)
		{
			if (field[h][w] == 's')
			{
				sh = h;
				sw = w;
			}
			if (field[h][w] == 'g')
			{
				gh = h;
				gw = w;
			}
		}
	}

	memset(seen, 0, sizeof(seen));
	dfs(sh, sw);

	// 結果
	if (seen[gh][gw]) 
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
}
