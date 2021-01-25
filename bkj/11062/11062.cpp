#include <iostream>
#include <cstring>
using namespace std;

int k_opt(int*, int*, int**, int**, int, int);
int m_opt(int*, int*, int**, int**, int, int);

int sum_arr(int *sarr, int start, int end){
    return sarr[end] - sarr[start-1];
}

int k_opt(int *arr, int *sarr, int **kdp, int **mdp, int start, int end){
    if(start == end){
        return arr[start];
    } else if(kdp[start][end]){
        return kdp[start][end];
    }
    
    int range_sum = sum_arr(sarr, start, end);
    int case1 = range_sum - m_opt(arr, sarr, kdp, mdp, start+1, end);
    int case2 = range_sum - m_opt(arr, sarr, kdp, mdp, start, end-1);
    return kdp[start][end] = max(case1, case2);
}

int m_opt(int *arr, int * sarr, int **kdp, int **mdp, int start, int end){
    if(start == end){
        return arr[start];
    } else if(mdp[start][end]){
        return mdp[start][end];
    }
    
    int range_sum = sum_arr(sarr, start, end);
    int case1 = range_sum - k_opt(arr, sarr, kdp, mdp, start+1, end);
    int case2 = range_sum - k_opt(arr, sarr, kdp, mdp, start, end-1);
    return mdp[start][end] = max(case1, case2);
}


int main(void){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int* arr = new int[N+1];
        int* sarr= new int[N+1];
        int** kdp = new int*[N+1];
        int** mdp = new int*[N+1];
        
        for(int i = 1; i <= N; i++) {
            kdp[i] = new int[N+1];
            mdp[i] = new int[N+1];
            memset(kdp[i], 0, sizeof(int) * (N+1));
            memset(mdp[i], 0, sizeof(int) * (N+1));
        }

        sarr[0] = 0;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            sarr[i] = sarr[i-1] + arr[i];
        }

        cout << k_opt(arr, sarr, kdp, mdp, 1, N) << '\n';
        
        delete arr, sarr;
        for(int i = 1; i <= N; i++) delete kdp[i], mdp[i];
        delete kdp, mdp;  
    }
}
