#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(500001);
	for (int i = 0; i < N; i++)
		cin >> A.at(i);
	
	int pairs = 0;
	sort(A.begin(), A.begin() + N);
	for (int i = 0; i < N;)
	{
		if (A.at(i) == A.at(i + 1))
		{
			++pairs;
			i += 2;
		}
		else
		{
			++i;
		}
	}
	cout << pairs << endl;
	return 0;
}
