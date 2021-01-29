#include <iostream>

using namespace std;

class Deque{
public:
    #define LEN 10000
    int f; // front idx
    int b; // back idx
    int s; // size
    int arr[LEN];

    Deque(){
        b = 0;
        s = 0;
        f = LEN-1;
    }

    void push_front(int n){
        arr[f] = n;
        f = (f + LEN - 1) % LEN;
        s++;
    }

    void push_back(int n){
        arr[b] = n;
        b = (b + LEN + 1) % LEN;
        s++;
    }

    int pop_front(){
        if(empty()){
            return -1;
        }
        int fv = front();
        f = (f + LEN + 1) % LEN;
        s--;
        return fv;
    }

    int pop_back(){
        if(empty()){
            return -1;
        }
        int bv = back();
        b = (b + LEN - 1) % LEN;
        s--;
        return bv;
    }

    int size(){
        return s;
    }

    int empty(){
        return s == 0;
    }

    int front(){
        if(empty()){
            return -1;
        } else {
            return arr[(f + LEN + 1) % LEN];
        }
    }

    int back(){
        if(empty()){
            return -1;
        } else {
            return arr[(b + LEN - 1) % LEN];
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    Deque deq;

    while(N--){
        string s;
        cin >> s;

        switch(s[0]){
            case 'p':{
                if(s[1] == 'u'){
                    int X;
                    cin >> X;
                    if(s[5] == 'f'){
                        deq.push_front(X);
                    } else if(s[5] == 'b'){
                        deq.push_back(X);
                    }
                } else if(s[1] == 'o'){
                    if(s[4] == 'f'){
                        cout << deq.pop_front() << '\n';
                    } else if(s[4] == 'b'){
                        cout << deq.pop_back() << '\n';
                    }
                }
                break;
            }
            case 's':{
                cout << deq.size() << '\n';
                break;
            }
            case 'e':{
                cout << deq.empty() << '\n';
                break;
            }
            case 'f':{
                cout << deq.front() << '\n';
                break;
            }
            case 'b':{
                cout << deq.back() << '\n';
                break;
            }
        }
    }
}
