#include <iostream>
#include <utility>

using namespace std;

class Runner{
public:
    int value;
    int rank;
    int idx;
};



void merge(int s, int m, int e, Runner* arr, Runner* tmp){
    int p1 = s;
    int p2 = m+1;
    int k = s;
    
    while(p1 <= m && p2 <= e){
        if(arr[p1].value >= arr[p2].value){
            tmp[k++] = arr[p1++];  
        } else {
            arr[p2].rank -= (m-p1+1);
            tmp[k++] = arr[p2++];
        }
    }

    while(p1 <= m){
        tmp[k++] = arr[p1++]; 
    }

    while(p2 <= e){
        tmp[k++] = arr[p2++];
    }

    for(int i = s; i <= e; i++){
        arr[i] = tmp[i];
    }
}

void mergeSort(int s, int e, Runner* arr, Runner* tmp){
    if(s < e){
        int mid = (s+e)/2;
        mergeSort(s, mid, arr, tmp);
        mergeSort(mid+1, e, arr, tmp);
        merge(s, mid, e, arr, tmp);
    }
}

int main(void){
    
    int N;
    cin >> N;

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    Runner * arr = new Runner[N];

    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;    
        arr[i].value = t;
        arr[i].rank = i+1;
        arr[i].idx = i;
    }

    Runner* tmp = new Runner[N];
    
    int start = 0;
    int end = N-1; 
    mergeSort(start, end, arr, tmp);
    
    int * answers = new int[N];
    for(int i = 0; i < N; i++){
        answers[arr[i].idx] = arr[i].rank;
    }

    for(int i = 0; i < N; i++){
        cout << answers[i] << '\n';
    }

    delete arr, tmp, answers;
}
