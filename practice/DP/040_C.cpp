#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> dp(N, INT_MAX);
	for (int i = 0; i < N; ++i) cin >> a[i];

	dp[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
		if (i > 1)
			dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[N - 1] << endl;
	return 0;
}
