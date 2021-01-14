#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    if( b == 0 ) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main(void){
    ll N;
    cin >> N;
    ll* arr = new ll[N];
    ll* lgcd = new ll[N];
    ll* rgcd = new ll[N];

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll answer = -1;
    ll K = 0;
    for(int i = 0; i < N ; i++) cin >> arr[i];
    
    
    lgcd[0] = arr[0];
    rgcd[N-1] = arr[N-1];

    for(int i = 1; i < N; i++){
        lgcd[i] = gcd(arr[i], lgcd[i-1]);
        rgcd[N-i-1] = gcd(arr[N-i-1], rgcd[N-i]);    
    }

    for(int i = 0; i < N; i++){
        ll k = arr[i];
        ll gcd_except_K;
        if(i == 0){
            gcd_except_K = rgcd[i+1];
        } else if(i == N-1){
            gcd_except_K = lgcd[i-1];
        } else {
            gcd_except_K = gcd(lgcd[i-1], rgcd[i+1]); 
        }
        if(k % gcd_except_K != 0 && gcd_except_K > answer){
            answer = gcd_except_K;
            K = k;
        }
    }

    if(!K){
        cout << answer << '\n';
    } else {
        cout << answer << ' ' << K << '\n';
    }

}

