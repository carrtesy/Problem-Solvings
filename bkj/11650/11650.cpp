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

    friend bool operator<(coord &c1, coord&c2);
};

bool operator< (coord &c1, coord &c2){
    if(c1.x == c2.x){
        return c1.y < c2.y;
    } else {
        return c1.x < c2.x;
    }
}

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
