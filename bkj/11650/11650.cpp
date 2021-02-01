
#include <iostream>
#include <algorithm>

using namespace std;

class coord{
public:
    int x;
    int y;

    coord(){
        x = 0;
        y = 0;
    }

    coord(int _x, int _y){
        x = _x;
        y = _y;
    }

    bool operator<(coord c) const{
        if(x == c.x){
            return y < c.y;
        } else{
            return x < c.x;
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    coord* arr=  new coord[N];

    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        arr[i] = coord(x, y);
    }

    sort(arr, arr+N);

    for(int i = 0; i < N; i++){
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}
