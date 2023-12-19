#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);

	for (auto&& a : A)
		cin >> a;

	for (const auto a : A)
		if (a % 2 == 0)
			cout << a << " ";
	cout << endl;

	return (0);
}
