#include <bits/stdc++.h>

using namespace std;

bool binsearch(int* arr, int N, int t){
    int s = 0, e = N-1;
    int m;
    bool found = 0;
    while(s <= e){
        m = (s + e) / 2;
        if(t < arr[m]){
            e = m-1;
        } else if(arr[m] < t){
            s = m+1;
        } else {
            found = true;
            break;        
        }
    }
    return found;
}

int main(void){
    int N, M;
    cin >> N;
    int *arr = new int[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    cin >> M;
    int *target = new int[M];
    for(int i = 0; i < M; i++) cin >> target[i];

    sort(arr, arr+N);

    for(int i = 0 ; i < M; i++){
        printf("%d\n", binsearch(arr, N, target[i]));
    }
    
    delete arr, target;
}
