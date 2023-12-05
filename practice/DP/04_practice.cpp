#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N, W;
	cin >> N >> W;

	vector<long long> w(N), v(N);
	for (int i = 0; i < N; ++i) cin >> w[i] >> v[i];

	vector<vector<long long> > dp(N + 1, vector<long long>(W + 1, 0));
	for (int i = 0; i < N; ++i) dp[0][i] = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int sum_w = 0; sum_w <= W; ++sum_w)
		{
			if (sum_w - w[i] >= 0)
				dp[i + 1][sum_w] = max(dp[i + 1][sum_w], dp[i][sum_w - w[i]] + v[i]);
			dp[i + 1][sum_w] = max(dp[i + 1][sum_w], dp[i][sum_w]);
		}
	}
	cout << dp[N][W] << endl;
}
