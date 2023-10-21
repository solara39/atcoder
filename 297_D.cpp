#include<iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int cnt = 0;

	while (A != B)
	{
		if (A > B)
		{
			A = A - B;
			cnt++;
		}
		if (A < B)
		{
			B = B - A;
			cnt++;
		}
	}
	cout << cnt << endl;
}
