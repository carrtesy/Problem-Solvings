void init(){
    for(int i = 1; i <= n; i++) p[i] = i, d[i] = 0;
}

int f(int a){
    int t = p[a];
    if(a==t) return t;
    f(t);
    d[a] += d[t];
    return p[a] = f(t);
}

void u(int a, int b, int w){
    f(a), f(b);
    LL x = d[a], y = d[b];
    a = f(a), b = f(b);
    p[a] = b, d[a] = w+y-x;
}
