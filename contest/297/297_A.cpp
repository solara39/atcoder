#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, D;
	cin >> N >> D;

	vector<int> T(101);
	for (int i = 0; i < N; i++)
		cin >> T[i];

	int flag = -1;
	for (int i = 1; i < N; i++)
	{
		if (T[i] - T[i - 1] <= D)
		{
			flag = T[i];
			break;
		}
	}
	cout << flag << endl;
}
