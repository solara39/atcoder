#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> a(M);
	vector<int> dp(N + 1, 0);
	for (int i = 0; i < M; ++i) cin >> a[i];
	dp[0] = 1;

	vector<bool> broken(N + 1, false);
	for (int i = 0; i < M; ++i)broken[a[i]] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (broken[i])
		{
			dp[i] = 0;
			continue;
		}
		if (i - 1 >= 0) dp[i] += dp[i - 1];
		if (i - 2 >= 0) dp[i] += dp[i - 2];
		dp[i] %= 1000000007;
	}
	cout << dp[N] << endl;
	return 0;
}
