#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;

    cout <<  "input: " << input << endl;

    for(char const &c: input){
        cout << c << endl;
    }

    stack <string> s;
    int C_is_on = 0; // "(" appeared
    int E_is_on = 0; // '[" appeared
    bool error = false;
    int len = input.length();
    
    for(int i = 0; i < len; i++){
        char c = input[i]; 
        string cs = &input[i];
        cout << "c: " <<  c << " cs: " << cs <<endl;
        switch(input[i]){
            case '(':{
                C_is_on++;
                s.push(cs);
                break;
            }
            case ')':{
                if (C_is_on <= 0){
                    error = true;
                    break;
                }
                string code = "2";
                if (s.top() ==")"){
                    s.pop();
                    C_is_on--;
                    s.push(code);
                } else {
                    //number
                    int n = stoi(s.top());
                    n = n << 1;
                    string n_str = to_string(n);
                    s.push(n_str);
                }
                break;
            }
            case '[':{
                E_is_on++;
                s.push(cs);
                break;
            }
            case ']':{
                E_is_on--;
                if (E_is_on <= 0){
                    error = true;
                    break;
                }
                string code = "3";
                if (s.top() ==")"){
                    s.pop();
                    E_is_on--;
                    s.push(code);
                } else {
                    //number
                    int n = stoi(s.top());
                    n = n * 3;
                    string n_str = to_string(n);
                    s.push(n_str);
                }
                break;
            }
        }

        if(error){
            break;
        }
    }
    
}
