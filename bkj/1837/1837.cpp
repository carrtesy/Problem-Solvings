#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int mod_str(string a, int q){
    int l = a.size();

    string _p;
    int p, r;
    for(int i = 0; i < l; i++){
        _p.append(1, a[i]);
        p = stoi(_p);
        r = p % q;
        _p = (r == 0)? "": to_string(r);
    }
    return r;
}
//checkisbad

/*
bool checkIsBad(string P, int x){
    int r = 0;
    for (int i = 0; i < P.size; i++){
        r = (r * 10 +( P[i] - '0')) % x;
    }

    if(r == 0){
        return true;
    } else {
        return false;
    }
}
*/

int main(void){
    string P;
    int K;
    cin >> P >> K;
    cout << P << " " << K << endl;
    // sieve
    bool* isPrime = new bool[K+1];
    memset(isPrime, 1, K+1); 
 
    vector<int> primes;   

    isPrime[1] = false;
    for(int i = 2; i <= K; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i + i; j <= K; j += i){
                isPrime[j] = false;
            }
        }
    }

    vector<int>::iterator it;
    bool isbad = false;
    int weekPoint;
    for(it = primes.begin(); it != primes.end(); it++){
        int mod = mod_str(P, *it);
        if(!mod){
            isbad = true;
            weekPoint = *it;
            cout << "BAD " << weekPoint << endl;  
            break;
        }
    }

    cout << "GOOD" << endl;
    
}
