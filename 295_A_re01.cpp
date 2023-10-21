#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<string> word = {"and", "not", "that", "the", "you"};
	int N;
	cin >> N;

	bool res = false;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (auto &nx : word)
		{
			if (s == nx)
				res = true;
		}
	}
	if (res)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
