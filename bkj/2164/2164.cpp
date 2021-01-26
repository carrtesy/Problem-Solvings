#include <bits/stdc++.h>

using namespace std;
int main(void){
    int N;
    cin >> N;
    bool *cards = new bool[N+1];
    memset(cards, 1, N+1);
    int card_left = N;
    int answer;
    bool abandon = true;

    while(1){
        bool found = false;
        for(int top = 1; top <= N; top++){
            if(!cards[top]){
                continue;
            }

            if(card_left == 1){
                found = true;
                answer = top;
                break;               
            }
    
            if(abandon){
                cards[top] = false;
                card_left--;
            }
            abandon = !abandon;
        }
        if(found) break;
    }
    cout << answer << endl;
}
