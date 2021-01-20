#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Element{
public:
    bool isValue;
    int value;
    char command;
/*
    Element(int value){
        this->isValue = true;
        this->value = value;
    }
*/
/*
    Element(char command){
        this->isValue = false;
        this->command = command;
    }
  */     
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;

    cout <<  "input: " << input << endl;

    for(char const &c: input){
        cout << c << endl;
    }

    stack <Element> s;
    int C_is_on = 0; // "(" appeared
    int E_is_on = 0; // '[" appeared
    bool error = false;
    int len = input.length();
    
    for(int i = 0; i < len; i++){
        char c = input[i];
        if(c == '(' || c == '['){
            s.push(new Element(c));
        } else if(c == ')'){
            int sum = 0;
            bool isInvalid = true;
            while(!s.empty()){
                Element element = stack.top();
                stack.pop();
                if(element.isValue){
                    sum += element.value;
                } else if (element.command == '('){a
                    if(sum == 0){
                        s.push(new element(2));
                    } else {
                        s.push(new element(sum * 2));
                    }
                    isInvalid = false;
                    break;
                } else {
                    isInvalid = true;
                    break;
                }
            }
            if(isInvalid){
                break;
            }
        }

    }
    
}
