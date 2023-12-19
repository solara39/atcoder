#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int A[110000];
	int B[110000];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];
	
	int C[220000];
	for (int i = 0; i < (N + M); i++)
	{
		if (i < N)
			C[i] = A[i];
		else
			C[i] = B[i - N];
	}
	sort(C, C + N + M);
	int posA[110] = {0};
	int posB[110] = {0};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N + M; j++)
		{
			if (A[i] == C[j])
			{
				posA[i] = j + 1;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N + M; j++)
		{
			if (B[i] == C[j])
			{
				posB[i] = j + 1;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
			cout << posA[i] << " ";
		else
			cout << posA[i] << endl;
	}
	for (int i = 0; i < M; i++)
	{
		if (i != M - 1)
			cout << posB[i] << " ";
		else
			cout << posB[i] << endl;
	}
}
