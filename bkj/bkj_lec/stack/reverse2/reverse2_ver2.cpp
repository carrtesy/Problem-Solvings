#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;
int main(void)
{
	string str;
	getline(cin, str);
	stack <char> s;

	int idx = 0;
	int strlen = str.length();
	while(1) {
		if(str[idx] == '<'){
			while(1){
				cout << str[idx++];
				if(str[idx] == '>'){
					cout << str[idx++];
					break;
				}
			}
		} else {
			while(1){
				if(str[idx] == ' '){
					while(!s.empty()){
						cout << s.top();
						s.pop();
					}
					cout << ' ';
					idx++;
					break;
				} else if(str[idx] == '<' || str[idx] == '\n' || idx >= strlen){
					while(!s.empty()){
						cout << s.top();
						s.pop();
					}					
					break;
				}
				s.push(str[idx++]);
			}

			
		}
			
		if(idx >= strlen){
			break;
		}
		
	}
}
