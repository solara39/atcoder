#include <iostream>
#include <cmath>

using namespace std;

long long pow(int x, int n)
{
	long long res;
	res = 1;

	while (n > 0)
	{
		if (n & 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

int main()
{
	long long x, n;
	cin >> x >> n;

	cout << pow(x, n) << endl;
	return 0;
}
