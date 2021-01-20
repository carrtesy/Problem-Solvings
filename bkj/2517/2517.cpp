#include <iostream>
#include <utility>

using namespace std;


void merge(int s, int m, int e, pair<int, int>* arr, pair<int, int>* tmp){
    int p1 = s;
    int p2 = m+1;
    int k = s;
    
    while(p1 <= m && p2 <= e){
        if(arr[p1].first >= arr[p2].first){
            tmp[k].first = arr[p1].first;
            tmp[k].second = arr[p1].second;
            k++;
            p1++;
            
        } else {
            tmp[k].first = arr[p2].first;
            cout << "-update-" <<endl;
            cout << m-p1+1 << endl;
            arr[p2].second -= ( m - p1 + 1);
            tmp[k].second = arr[p2].second;
            cout << arr[p2].second << endl;
            cout << tmp[k].second << endl;
            k++;
            p2++;
        }
    }

    while(p1 <= m){
        tmp[k].first = arr[p1].first;
        tmp[k].second = arr[p1].second;
        k++;
        p1++;
    }

    while(p2 <= e){
        tmp[k].first = arr[p2].first;
        tmp[k].second = arr[p2].second;
        k++;
        p2++;
    }

    for(int i = s; i <= e; i++){
        arr[i].first = tmp[i].first;
        arr[i].second = tmp[i].second;
        cout << arr[i].first;
    }
    cout << endl;
}

void mergeSort(int s, int e, pair<int, int>* arr, pair<int, int>* tmp){
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
    pair<int, int>* arr = new pair<int, int>[N];
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;    
        arr[i].first = t;
        arr[i].second = i+1;
    }

    for(int i = 0; i < N; i++){
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
    pair<int, int>* tmp = new pair<int, int>[N];
    
    int start = 0;
    int end = N-1; 
    mergeSort(start, end, arr, tmp);
    
    for(int i = 0; i < N; i++){
        cout << arr[i].first << ' ' << arr[i].second << endl;
    }
}



