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
        cout << endl;
    }

    if(only_zeros){
        cout << 0 << endl;
        return 0;
    }

    int side = 1;
    int _n = n, _m = m;

    while(1){
        //debug
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                cout << arr[r][c] << ' ';
            }
            cout << endl;
        }
        //
        cout << endl;

        bool found = false;
        for(int r = 0; r < _n - 1; r++){
            for(int c = 0; c < _m -1; c++){
                cout << r << ' ' << c << endl;
                bool isSquare = arr[r][c] && arr[r][c+1] && arr[r+1][c] && arr[r+1][c+1];
                cout << 'r' << ' ' << r << " c " << c << ' '<< arr[r][c] << endl;
                cout << 'r' << ' ' << r << " c+1 " << c << ' ' << arr[r][c+1] << endl;
                cout << "r+1" << ' ' << r << " c " << c << ' ' << arr[r+1][c] << endl;
                cout << "r+1"  << ' ' << r << " c+1 " << c << ' ' << arr[r+1][c+1] << endl;
                arr[r][c] = isSquare;
                if(isSquare){
                    found = true;
                    cout << "found!" << endl;
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
