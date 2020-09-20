#include <iostream>

using namespace std;
int main(void){
    int N;
    cin >> N;
    long long digits = 0;
    int cur = 1;
    int length = 1;
    int range_num = 9;

    while(1){
        if(N < cur * 10){
            digits += (N - cur + 1) * length;
            break; 
        } else {
            digits += range_num * length;
            length++;
            range_num *= 10;
        }
        cur *= 10;
    }

    cout << digits << endl;
}
