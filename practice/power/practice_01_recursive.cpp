#include <iostream>

using namespace std;

long long powpow(int x, int n)
{
	if (n == 0)
		return 1;

	long long res;
	res = powpow(x, n / 2);
	res *= res;
	if (n % 2 == 1)
		res *= x;
	return res;
}

int main()
{
	int x, n;
	cin >> x >> n;

	cout << powpow(x, n) << endl;
}
