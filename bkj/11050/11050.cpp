#include <iostream>
#include <cstring>
using namespace std;

int fact(int* memo, int n){
    if(memo[n]) return memo[n];
    if(n == 0) return 1;
    return memo[n] = n * fact(memo, n-1);
}

int main(void){
    int N, K;
    cin >> N >> K;
    int* memo = new int[N+1];
    memset(memo, 0, (N+1) * sizeof(int));
    cout << fact(memo, N) / fact(memo, N-K) / fact(memo, K) << '\n';
    delete memo;
    
}
