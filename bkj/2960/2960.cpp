#include <bits/stdc++.h>

using namespace std;
int main(void){
    int N, K;
    cin >> N >> K;

    bool* isPrime = new bool[N+1];
    memset(isPrime, 1, N+1);

    int cnt = 0;
    int answer = 0;
    bool found = false;
    isPrime[0] = 0, isPrime[1] = 0;

    for(int i = 2; i <= N; i++){
        if(!isPrime[i]) continue;
        for(int j = i; j <= N; j += i){
            if(!isPrime[j]) continue;
            if(j != i) isPrime[j] = false;
            cnt++;
            if(cnt == K){
                found = true;
                answer = j;
                break;
            }
        }
        if(found) break;
    }
    cout << answer << '\n';
    delete isPrime;
}
