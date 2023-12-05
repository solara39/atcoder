#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> values;
	values.push_back(1);
	for (int i = 6; i <= N; i *= 6) values.push_back(i);
	for (int i = 9; i <= N; i *= 9) values.push_back(i);
	vector<int> dp(N + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (size_t j = 0; j < values.size(); ++j)
		{
			int value = values[j];
			if (i >= value)
				dp[i] = min(dp[i], dp[i - value] + 1);
		}
	}
	cout << dp[N] << endl;
	return 0;
}
