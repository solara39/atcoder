#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<vector<int> > field;

void dfs(int h, int w)
{
	field[h][w] = 0;

	for (int dh = -1; dh <=1; ++dh)
	{
		for (int dw = -1; dw <= 1; ++dw)
		{
			int nh = h + dh;
			int nw = w + dw;
			if (nh < 0 || nw < 0 || nh >= H || nw >= W)
				continue;
			if (field[nh][nw] == 0)
				continue;
			dfs(nh, nw);
		}
	}
}

int main()
{
	while (cin >> H >> W)
	{
		if (H == 0 || W == 0)
			break;
		field.assign(H, vector<int>(W, 0));
		for (int h = 0; h < H; ++h)
		{
			for (int w = 0; w < W; ++w)
				cin >> field[h][w];
		}
		int count = 0;
		for (int h = 0; h < H; ++h)
		{
			for (int w = 0; w < W; ++w)
			{
				if (field[h][w] == 0)
					continue;
				dfs(h, w);
				++count;
			}
		}
		cout << count << endl;
	}
	
}
