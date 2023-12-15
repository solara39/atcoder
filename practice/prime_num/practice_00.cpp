#include <iostream>
#include <math.h>

using namespace std;

int isPrime(int num)
{
	if (num < 2)
		return false;
	for (int i = 2; i < num; ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	cin >> num;

	if (isPrime(num))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
