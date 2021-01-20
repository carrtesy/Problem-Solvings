#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int ** arr = new int*[N+1];
    for(int r = 1; r <= N; r++){
        arr[r] = new int[N+1];
        arr[r][0] = 0;

        for(int c = 1; c <= N; c++){
            int tmp;
            cin >> tmp;
            arr[r][c] = arr[r][c-1] + tmp;
        }
    }

    while(M--){
        int x1, y1, x2, y2, answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int r = x1; r <= x2; r++){
            answer += (arr[r][y2] - arr[r][y1-1]);
        }
        cout << answer << '\n';
    }

}
