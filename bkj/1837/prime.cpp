#include <iostream>

using namespace std;
int main(void){
    int max = 120;
    bool* checked = new bool[121];

    for(int i = 2; i < max; i++){
        if(checked[i] == false){
            cout << i << endl;
            for(int j = i+i; j < max; j += i){
                checked[j] = true;
            }
        }
    }
}
