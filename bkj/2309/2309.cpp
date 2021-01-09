#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int* heights = new int[9];
    int sum = 0;
    for (int h = 0; h < 9; h++){
        cin >> heights[h];
        sum += heights[h];
    }
    sort(heights, heights+9);

    int i, j;
    bool found = false;
    for(i = 0; i < 9; i++){
        for(j = i+1; j < 9; j++){
            int dwarf1 = heights[i];
            int dwarf2 = heights[j];
            if (sum - dwarf1 - dwarf2 == 100){
                found = true;
                break;
            }
        }
        if (found) break;
    }

    for (int h = 0; h < 9; h++){
        if(h == i || h == j){
            continue;
        }
        cout << heights[h] << endl;
    }
}
