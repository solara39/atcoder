#include<iostream>
#include<string>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < 8; i++)
	{
		if (S[i] == 'B')
		{
			for (int j = i; j < 8; j++)
			{
				if (S[j] == 'B' && (j - i) % 2 == 1)
					flag1 = 1;
			}
		}
		if (S[i] == 'R')
		{
			int K;
			int R;
			for (int j = i; j < 8; j++)
			{
				if (S[j] == 'K')
					K = j;
				if (S[j] == 'R')
					R = j;
				if (R - K > 0 && K - i > 0)
					flag2 = 1;
			}
		}
	}
	if (flag1 && flag2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
