#include <bits/stdc++.h>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        int n;
        char str[10];
        cin >> n;
        if(!n) break;
        sprintf(str, "%d", n);

        int front = 0;
        int back = strlen(str) - 1;
        bool is_pnum = true;
        while(front <= back){
            if(str[front] == str[back]){
                front++; 
                back--;
                continue;
            } else {
                is_pnum = false;
                break;
            }
        }

        if(is_pnum) cout << "yes" << '\n';
        else cout << "no" << '\n';
        
    }
}
