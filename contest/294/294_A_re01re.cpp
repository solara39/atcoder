#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    // 長さ N の配列
    vector<int> A(N);
    // 順に入力
    for (auto&& a : A)
        cin >> a;
    for (const auto a : A) 
        // 2 で割ったあまりが 0 なら偶数
        if (a % 2 == 0)
            cout << a << " ";
    cout << endl;
    return 0;
}
