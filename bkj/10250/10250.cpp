#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int H, W, N, roomnum;
        cin >> H >> W >> N;
        int YYOO = N % H ? (N % H) * 100: H * 100;
        int OOXX = N % H ? N / H + 1: N / H;
        roomnum = YYOO + OOXX;
        cout << roomnum << '\n';
    }
}
