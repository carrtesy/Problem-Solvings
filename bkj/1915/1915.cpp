#include <iostream>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;

    bool **arr = new bool*[n];
    bool only_zeros = true;

    for(int i = 0; i < n; i++){
        arr[i] = new bool[m];
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            bool is_one = (s[j] == '1');
            only_zeros &= !is_one;
            arr[i][j] = is_one;
        }
    }

    if(only_zeros){
        cout << 0 << endl;
        return 0;
    }

    int side = 1;
    int _n = n, _m = m;

    while(1){
        bool found = false;
        for(int r = 0; r < _n - 1; r++){
            for(int c = 0; c < _m -1; c++){
                bool isSquare = arr[r][c] && arr[r][c+1] && arr[r+1][c] && arr[r+1][c+1];
                arr[r][c] = isSquare;
                if(isSquare){
                    found = true;
                }
            }
        }
    
        _n--;
        _m--;

        if(!found){
            break;
        } else {
            side++;
            if(_n < 2 || _m < 2){
                break;
            }
        }
    }

    cout << side * side << endl;
    
}
