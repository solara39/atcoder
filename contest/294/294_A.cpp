#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int A[110];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	int j = 0;
	int res[110] = {0};
	for (int i = 0; i < N; i++)
	{
		if (A[i] % 2 == 0)
		{
			res[j] += A[i];
			j++;
		}
	}
	for (int i = 0; i < 110; i++)
	{
		if (res[i] && res[i + 1])
			cout << res[i] << " ";
		else if (res[i + 1] == 0)
		{
			cout << res[i] << endl;
			break;
		}
	}
}
