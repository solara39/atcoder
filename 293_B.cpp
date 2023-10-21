#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int A[210000];
	int res[210000] = {0};
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++)
	{
		if (!res[i])
				res[A[i]]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!res[i])
			count++;;
	}
	cout << count << endl;
	for (int i = 1; i <= N; i++)
	{
		if (!res[i])
			cout << i << " ";
	}
	cout << endl;
	
}
