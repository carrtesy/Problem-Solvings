#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, S;
    cin >> N >> S;
    int * arr = new int[N+1];
    for(int i=0; i < N; i++) cin >> arr[i];

    int start = 0, end = 0;
    int sum = arr[0];
    int minlength = 1000000;
    while(1){
        if (sum >= S){
            minlength = end-start+1 < minlength? end-start+1:minlength;
            sum -= arr[start++];        
        } else {
            sum += arr[++end];
        }

        if(end == N){
            break;
        }
    }

    int answer = minlength == 1000000? 0 : minlength;
    cout << answer << endl;
}
