#include <iostream>

using namespace std;
int main(void){
    int first;
    cin >> first;
    bool is_mixed = false;

    if(first == 1){
        for(int i = 2; i <= 8; i++){
            int note;
            cin >> note;
            if(i != note){
                is_mixed = true;
                break;
            }
        }
        
        if(is_mixed){
            cout << "mixed" << endl;
        } else{
            cout << "ascending" << endl;
        }

    } else if(first == 8){
        for(int i = 7; i >= 1; i--){
            int note;
            cin >> note;
            if(i != note){
                is_mixed = true;
                break;
            }
        }

        if(is_mixed){
            cout << "mixed" << endl;
        } else{
            cout << "descending" << endl;
        }

    } else {
        cout << "mixed" << endl;
    }


}
