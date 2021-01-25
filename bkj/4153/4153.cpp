#include <iostream>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int x, y, z;
        bool isRight;
        cin >> x >> y >> z;
        if(!x) break;

        isRight = false;
        isRight |= ((x+y > z) && (x*x + y*y == z*z));
        isRight |= ((y+z > x) && (y*y + z*z == x*x));
        isRight |= ((z+x > y) && (z*z + x*x == y*y));

        if(isRight){
            cout << "right" << '\n';
        } else {
            cout << "wrong" << '\n';
        }
    }
}
