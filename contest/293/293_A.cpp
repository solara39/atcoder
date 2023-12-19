#include<iostream>
#include<string>

using namespace std;

int main()
{
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		char temp;
		temp = S[2 * i];
		S[2 * i] = S[2 * i + 1];
		S[2 * i + 1] = temp;
	}
	cout << S << endl;
}
