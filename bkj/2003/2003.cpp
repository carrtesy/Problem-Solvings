#include <iostream>

using namespace std;
int main(void){
    int N, M;
    int* arr = new int[N];
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int start = 0, end = 0;
    int sum = 0;
    int answer = 0;
    while(1){
        if(sum < M){
            if(end >= N){
                break;
            }
            sum += arr[end++]; 
        } else if(sum >= M){
            if(start >= N){
                break;
            }
            if(sum == M){
                answer++;
            }
            sum -= arr[start++];
        }
    }

    if(sum == M){
        answer++;
    }

    cout << answer << endl;
}
