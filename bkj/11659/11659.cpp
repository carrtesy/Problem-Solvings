#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *arr = new int[N+1];
    arr[0] = 0;
    for(int n = 1; n <= N; n++) {
        int tmp;
        cin >> tmp;
        arr[n] = arr[n-1] + tmp;
    }

    while(M--){
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }

    delete arr;
}
