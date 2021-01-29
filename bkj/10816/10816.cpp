#include <iostream>
#include <algorithm>
using namespace std;

struct info{
    int num;
    int cnt;
};

bool compinfo (info &a, info &b){
    return a.num < b.num;
}

void binsearch(info* arr, int n, int val, bool cntprintmode){
    int s = 0;
    int e = n-1;
    int m;
    bool found = false;
    while(s <= e){
        m = (s + e) / 2;
        int cur = arr[m].num;
        if(val < cur){
            e = m - 1;
        } else if(cur < val){
            s = m + 1;
        } else {
            if(cntprintmode){
                printf("%d ", arr[m].cnt);
                return;
            }
            found = true;
            break;
        }
    }

    if(found){
        arr[m].cnt++;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
 
    // n numbers   
    cin >> n;
    int* arr = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // m numbers
    cin >> m;
    info* arr2 = new info[m];
    int* arr2_cp = new int[m];
    
    for(int i = 0 ; i < m; i++){
        int num;
        cin >> num;
        info p = {num, 0};
        arr2[i] = p;
        arr2_cp[i] = num;
    }

    // sort
    sort(arr2, arr2+m, compinfo);

    // search
    for(int i = 0; i < n; i++){
        binsearch(arr2, m, arr[i], 0);      
    }

    // print answer
    for(int i = 0; i < m; i++){
        binsearch(arr2, m, arr2_cp[i], 1);
    }

    delete arr, arr2, arr2_cp;
}
