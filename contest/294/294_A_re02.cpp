#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int N;
    cin >> N;
    
    // 長さ N の配列
    vector<int> A(N);
    // 順に入力
    for (auto&& a : A)
        cin >> a;
    // 奇数を取り除いた配列を作る
    vector<int> B{begin(A), remove_if(begin(A), end(A), [](auto i){return (i % 2 != 0);})};
    // 順に出力
    for (const auto b : B)
        cout << b << " ";
    cout << endl;
    return 0;
}
