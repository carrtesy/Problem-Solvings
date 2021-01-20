#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct _Info{
    int a, b, c;
    _Info() {};
} Info;

int find(int a, int *pr){
    if (a == pr[a]) return a;
    return pr[a] = find(pr[a], pr);
}

void unionf(int a, int b, int* pr){
    a = find(a, pr);
    b = find(b, pr);
    pr[a] = b;
}

bool comp(Info a, Info b){
    return a.c < b.c;
}

int main(void){
    int N, M;
    int answer = 0;
    cin >> N >> M;

    Info * edge;
    edge = new Info[M];

    int * pr = new int[N+1];
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].a = a;
        edge[i].b = b;
        edge[i].c = c;
    }

    
    for(int i = 0; i < N; i++){
        pr[i] = i;
    }

    sort(edge, edge + M, comp);

    int cnt = 0; // linked edges -> cnt == n-1
    for(int i = 0; i < M; i++){
        // read info
        int a, b, c;
        a = edge[i].a;
        b = edge[i].b;
        c = edge[i].c;
    
        if(find(a, pr) != find(b, pr)){
            unionf(a, b, pr);
            answer += c;
            cnt++;
        }
    }    

    cout << answer << endl;
}
