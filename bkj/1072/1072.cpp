#include <iostream>

using namespace std;
int main(void){
    int X, Y;
    cin >> X >> Y;

    int max = 1000000000;
    int Z = Y * 100 / X;


    int low = 0;
    int high = max+1;
    int answer;

    if(z>=99){
        answer = -1;
    } else {
        while(low < high){
            int mid = (low + high) / 2;
            long tmp = (100 * (Y + mid) / (X + mid));

            if(tmp <= Z){
                low = mid + 1;
            } else {
                high = mid;
            }
        }   
        answer = high > max ? -1 else high;
    }
}
