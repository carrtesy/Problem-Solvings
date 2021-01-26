#include <bits/stdc++.h>

using namespace std;

class MinHeap{
public:
    int arr[100001];
    int len;
    
    MinHeap(){
        len = 0;
        memset(arr, 0, sizeof(arr));    
    }

    void printHeap(){
        cout << "printHeap: ";
        for(int i = 1; i <= len; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    void push(int n){
        int cur = ++len;
        while(cur > 1){
            int par = cur / 2;
            int parVal = arr[par];
            if (parVal > n){
                arr[cur] = arr[par];
                cur = par;
            } else {
                break;
            }
        }
        arr[cur] = n;
    }

    void pop(){
        if(len == 0){
            cout << "0\n"; 
            return;
        }
        
        cout << arr[1] << '\n';
        int cur = 1;
        int lastVal = arr[len--];
        
        while(cur <= len){
            int leftChildIdx = cur * 2;
            int rightChildIdx = cur * 2 + 1;
            
            if(leftChildIdx > len){
                break;
            }

            int leftChild = arr[leftChildIdx];
            int rightChild = arr[rightChildIdx]? arr[rightChildIdx]: -1;
            int minChild, minIdx;
            
            if(rightChild == -1){
                minIdx = leftChildIdx;
                minChild = leftChild;
            } else {
                minIdx = leftChild < rightChild? leftChildIdx: rightChildIdx;
                minChild = leftChild < rightChild? leftChild: rightChild;
            }

            if(lastVal > minChild){
                arr[cur] = minChild;
                cur = minIdx;
            } else {
                break;
            }
            
        }

        arr[cur] = lastVal;
    }
    
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; 
    cin >> N;
    MinHeap mhp;    

    while(N--){
        int n;
        cin >> n;
        if(n){
            // push
            mhp.push(n);
        } else {
            // pop
            mhp.pop();
        }
    }
}
