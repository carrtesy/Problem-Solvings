#include <iostream>

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
    int k;
    int answer;
    
    while(s <= e){
        int collected = 0;
        k = (s + e) / 2;
        for(int t = 0; t < N; t++){
            collected += trees[t] > k ? trees[t] - k: 0; 
        }

        if(collected < M){
            e = k-1;
        } else if (collected > M){
            answer = k;
            s = k+1;
        } else {
            break;
        }
    }

    cout << k << endl;
}
