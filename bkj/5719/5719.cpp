#include <iostream>
#define INF 10000

using namespace std;

struct info {
    int v, p;
    info(int vv, int pp){
        v = vv;
        p = pp;
    }
};

void dijk(){
    priority_queue<int> pq;
    
}

int main(void){
    while(1){
        int N, M, S, D;
        cin >> N >> M;
        if(!N && !M){
            break;
        }
        cin >> S >> D;

        info** graph = new info*[N];
        for(int i = 0
        vector<info> *graph = new vector<info>[N];
        
        for(int edge = 0; edge < M; edge++){
            int U, V, P;
            cin >> U >> V >> P;
            cout << U << ' ' << V << ' ' << P << endl;
            graph[U].push_back(info(V, P));
        }

        dijk(graph);
    }
}
