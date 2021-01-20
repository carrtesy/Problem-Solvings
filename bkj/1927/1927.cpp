#include <iostream>

using namespace std;

class minHeap{
public:
    int *data;
    int size;
    
    minHeap(int N){
        this->data = new int[N+1];
        this->size = 0;
    }

    void printarr(){
        if(this->size == 0){
            return;
        }

        for(int i = 1 ; i <= this->size; i++){
            cout << this->data[i] << ' ';
        } 
        cout << endl;
    }

    void push(int val){
        int cur =  this->size + 1;
        int par = cur / 2;

        while(cur > 1){
            if(this->data[par] > val){
                this->data[cur] = this->data[par];
                cur = par;
                par = cur / 2;
            } else {
                break;
            }
        }

        this->data[cur] = val;
        this->size++;
    }

    void pop(){
        if(!this->size){
            cout << 0 << endl;
            return;
        }
    
        cout << data[1] << endl;
        int lastVal = data[this->size];
        int cur = 1;
        this->size--;
        while(1){
            int Lchild, Rchild;
            int Lidx = cur << 1 , Ridx = (cur << 1) + 1;
            Lchild = Lidx <= this->size ? this->data[Lidx] : -1;
            Rchild = Ridx <= this->size ? this->data[Ridx] : -1;
            
            if(Lchild == -1){
                // no child
                break;
            } else if(Lchild != -1 && Rchild == -1){
                // only left child
                if(Lchild < lastVal){
                    data[cur] = Lchild;
                    cur = Lidx;
                } else {
                    break;
                }
            } else {
                // right, left
                int min_child, min_idx;
                min_child = Lchild < Rchild? Lchild: Rchild;
                min_idx = Lchild < Rchild? Lidx: Ridx;

                if(min_child < lastVal){
                    data[cur] = min_child;
                    cur = min_idx;
                } else {
                    break;
                }
            }
        }
        data[cur] = lastVal;
    }
};

int main(void){
    int N;
    cin >> N;
    minHeap h(N);
    while(N--){
        int n;
        cin >> n;

        if(!n){
            h.pop();
        } else {
            h.push(n);
        }
    }

}
