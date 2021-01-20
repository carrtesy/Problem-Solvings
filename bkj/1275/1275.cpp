#include <iostream>
#define ll long long

using namespace std;

class SegmentTree{
public:
    int N;
    int S;
    ll* data;
    ll* tree;
    
    SegmentTree(int n, int* arr){
        int s = 1;
        N = n;
        while(s < n) s <<= 1;
        S = s;
        data = (ll*)arr;
        tree = new ll[2*s];

        cout << "INIT: S: " << S << " N: " << N << endl; 
    }

    void printTree(){
        for(int i = 1; i < 2 * S; i++){
            cout << tree[i] << ' ';
        }
        cout << endl;
    }

    void initTree(){
        // leaf
        for(int i = S; i <= N; i++){
            tree[i] = data[i-S+1];
        }
        for(int i = N + 1; i <= 2*S; i++){
            tree[i] = 0;
        }

        for(int i = S-1; i >=0; i--){
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }  

        printTree();
    }

};


int main(void){
    int N, Q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    int* arr = new int[N+1];
    for(int i = 1; i <=N; i++) cin >> arr[i];


    SegmentTree st(N, arr);
    for(int i = 0; i < Q; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << x << y << a << b;
    }
    
}
