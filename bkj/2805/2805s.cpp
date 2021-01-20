#include <iostream>
#define ll long long
using namespace std;
int main(void){

    int N, M;
    cin >> N >> M;
    int* trees = new int[N];
    int max_height = 0;
    for(int i = 0; i < N; i++){ 
        cin >> trees[i];
        if(trees[i] > max_height){
            max_height = trees[i];
        }
    }

    int s = 0;
    int e = max_height;
    int mid;
    ll result;
    
    while(1){
        mid = (s+e) / 2;
        ll sum = 0;
        for(int i = 0; i < N; i++){
            sum += trees[i] > mid? trees[i] - mid : 0;
        }

        if(sum == M){
            result = mid;
            break;
        } else if(sum < M){
            e = mid - 1;
        } else {
            result = mid;
            s = mid + 1;
        }
        if(s>e){
            break;
        }
    }

    cout << result << endl;
}
