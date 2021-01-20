#include <iostream>

using namespace std;

int main(void){
    int answer = 0;
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        answer += tmp * tmp;
    }
    cout << answer % 10 << endl;
}
