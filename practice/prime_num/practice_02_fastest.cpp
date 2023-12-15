#include <iostream>
#include <cmath>

using namespace std;

/*
「合成数xはp≦√xを満たす素因子pをもつ」＝「xが合成数ならば、√x以下の約数を持つ」
ループの終了条件がMath.Sqrt(num)までになっている
*/

int isPrime(int num)
{
	if (num < 2)
		return false;
	else if (num == 2)
		return true;
	else if (num % 2 == 0)
		return false;
	
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; ++ i)
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
}
