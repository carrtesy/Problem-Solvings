#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SegmentTree {
public:
    int S;
    ll* tree;

    SegmentTree(ll* data, int N){
        S = 1;
        while(S < N) S <<= 1;
        tree = new ll[2*S];
        memset(tree, 0, sizeof(ll) * 2 * S);
        for(int i = 0; i < N; i++) tree[S+i] = data[i];

        for(int i = S-1; i > 0; i--) {
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    void printTree(){
        int idx = 1;
        int range = 1;
        while(1){
            for(int i = idx; i < idx + range; i++){
                cout << tree[i] << ' ';
            }
            cout << '\n';
            
            if(idx + range >= 2 * S){
                break;
            }
            
            idx += range;
            range <<= 1;
        }
    }
 
    ll query(int node, int left, int right, int qleft, int qright){
        // out of range
        if(right < qleft || qright < left){
            return 0;
        }
        // in the range
        else if(qleft <= left && right <= qright){
            return tree[node];
        }

        // on the edge
        else{
            int mid = (left + right) / 2;
            ll leftquery = query(node * 2, left, mid, qleft, qright);
            ll rightquery = query(node * 2 + 1, mid+1, right, qleft, qright);
            return leftquery + rightquery;
        }
        
    } 

    void update(int node, int left, int right, int K, ll value){
        if(node == S+K-1){
            tree[node] = value; 
        }

        else if(right < K || K < left){
            return;
        }

        else{
            int mid = (left + right) / 2;
            update(node * 2, left, mid, K, value);
            update(node * 2 + 1, mid+1, right, K, value);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
      
    }
    
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    
    ll* data = new ll[N];
    for(int i = 0; i < N; i++) cin >> data[i];

    SegmentTree st = SegmentTree(data, N);

    while(M+K){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if(a == 1){
            st.update(1, 1, st.S, b, c);
            M--;   
        } else if(a == 2){
            printf("%lld\n", st.query(1, 1, st.S, b, c));
            K--;
        }
    }
    
}
