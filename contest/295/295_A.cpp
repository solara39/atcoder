#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string W[101];
	string thereIs = "No";
	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
		if (W[i] == "and" || W[i] == "not" || W[i] == "that" || W[i] == "you" || W[i] == "the")
		{
			thereIs = "Yes";
		}
	}
	cout << thereIs << endl;
	return 0;
}
