#include <iostream>
#define ll long long
#define MOD 1234567891

using namespace std;

ll pow(ll a, ll n){
    if(n == 0){
        return 1;
    } else if(n == 1){
        return a;
    }

    ll half = pow(a, n/2);
    if(n % 2){
        return half * half * a;
    } else {
        return half * half;
    }
}

int main(void){
    ll N;
    cin >> N;
    char str[50];
    cin >> str;

    ll hash_val = 0;
    ll r_i = 1;
    for(int i = 0; i < N; i++){
        ll a = str[i] - 'a' + 1;
        hash_val = (a * r_i + hash_val) % MOD;
        r_i = (r_i * 31) % MOD;
    }
    
    printf("%lld\n", hash_val);
}
