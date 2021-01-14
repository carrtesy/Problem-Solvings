#include <iostream>
#include <unistd.h>

#define ll long long

using namespace std;
class SegmentTree{
public:
    int N;
    int S;
    ll* tree;
    ll* data;

    SegmentTree(ll* arr, int n, int s){
        N = n;
        S = s;
        data = arr;
        tree = new ll[2*s];
    }

    void printTree(){
        int power = 0;

        for(int i = 1; i < 2*S; i++){
            cout << tree[i] << ' ';
        }
        cout << endl;
    }

    ll makeTree(int node, int left, int right){
        // leaf?
        if(left == right){
            if(left <= N){
                tree[node] = data[left];
            } else {
                tree[node] = 0;
            }
            return tree[node];
        }
        
        int mid = (left + right) / 2;
        tree[node] = makeTree(node * 2, left, mid);
        tree[node] += makeTree(node *2 + 1, mid+1, right);
        
        return tree[node];
        
    }

    ll query(int node, int left, int right, int qLeft, int qRight){
        // outside query
        if(qRight < left || right < qLeft){
            return 0;
        }
        // inside query
        else if(qLeft <= left && right <= qRight){
            return tree[node];
        }
        // in and out
        else{
            int mid = (left + right)/2;
            return query(node * 2, left, mid, qLeft, qRight) +
            query(node*2+1, mid+1, right, qLeft, qRight);
        }
    }

    void update(int index, ll value){
        int cur = S+index-1;
        tree[S+index-1] = value;

        while(cur > 1){
            int par = cur/2;
            tree[par] = tree[par*2] + tree[par*2+1];
            cur = par; 
        }
         
    }
};


using namespace std;
int main(void){
    int N, M, K;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    
    ll * nums = new ll[N+1];
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    int s = 1;
    while (s < N) s <<= 1;
    
    SegmentTree st(nums, N, s);
    st.makeTree(1, 1, s);

    while(M+K){
        int command, a, b;
        cin >> command >> a >> b;

        if(command == 1){
            st.update(a, b);
            M--;
        } else {
            ll q = st.query(1, 1, s, a, b);
            cout << q << '\n';
            K--;
        }
    }
}
