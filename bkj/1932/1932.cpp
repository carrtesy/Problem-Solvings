#include <iostream>

using namespace std;
int main(void){
    int N;
    cin >> N;
    int **tri = new int*[N];
    int answer = 0;
    
    tri[0] = new int[1];
    cin >> tri[0][0];
    
    for(int r = 1; r < N; r++){
        int tmp;
        tri[r] = new int[r+1];
        cin >> tmp;
        tri[r][0] = tri[r-1][0] + tmp;
        
        for(int c = 1; c < r; c++){
            cin >> tmp;
            tri[r][c] = max(tri[r-1][c-1], tri[r-1][c]) + tmp;
        }
        
        cin >> tmp;
        tri[r][r] = tri[r-1][r-1] + tmp;
    }


    for(int c = 0; c < N; c++){
        answer = answer < tri[N-1][c]? tri[N-1][c]: answer;
    }

    cout << answer << endl;

}
