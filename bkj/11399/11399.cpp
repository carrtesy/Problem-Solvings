#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, answer = 0;
    cin >> N;
    int* time = new int [N];
    for(int i = 0 ; i < N; i++) cin >> time[i];
    sort(time, time+N);
    for(int i = 0; i < N; i++) answer += (time[i] * (N-i));
    cout << answer << endl;
    delete time;
}
