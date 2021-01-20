#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, S;
    cin >> N >> S;
    int * arr = new int[N];
    for(int i=0; i < N; i++) cin >> arr[i];

    int s = 0, e = 0;
    int sum = 0;
    int answer = 0;
    while(e < N){
        while(e < N && sum < S) sum += arr[e++];
        while(s < N && sum >= S) sum -= arr[s++];
        int cand = e-s+1;

        if(sum + arr[s-1] >= S){
            if(cand <= 0){
                continue;
            } else {
                if(!answer){
                    answer = cand;
                } else {
                    if(cand < answer){
                        answer = cand;
                    }
                }   
            }          
        }
    }
    cout << answer << endl;
}
