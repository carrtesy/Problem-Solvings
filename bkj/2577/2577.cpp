#include <iostream>

using namespace std;
int main(void){
    int A, B, C;
    int num;
    int digits[10]; 
    cin >> A >> B >> C;
    num = A*B*C;

    for(int i = 0; i < 10; i++){
        digits[i] = 0;
    }    

    while(1){
        int digit;
        digit = num % 10;
        digits[digit]++;
        num = num / 10;
        if(num == 0){
            break;
        } 
    }

    for(int i = 0; i < 10 ; i++){
        cout << digits[i] << endl;
    }
    
}
