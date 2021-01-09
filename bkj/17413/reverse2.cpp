#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;
int main(void)
{
	string str;
	getline(cin, str);
	istringstream ss(str);
	int flag = 0;

	while(ss){
		string word;
		ss >> word;
		stack <char> s;
		int idx, strlen;
	
		idx = 0;
		strlen = word.length();
		//cout << word;

		while(idx < strlen){
			if(word[idx] == '<'){
				flag = 1;
				// empty the stack
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				
				// resolve the tag
				while(1){
					if(idx >= strlen){
						break;
					} else if (word[idx] == '>') {
						cout << word[idx++];
						flag = 0;
						break;
					}
					cout << word[idx++];
				}
				//cout << word[idx++];
			} else if (word[idx] == '>'){
				cout << word[idx++];
				flag = 0;
			} else {
				if(flag){
					cout << word[idx++];
				} else {
					s.push(word[idx++]);
				}
			}
		}

		while(!s.empty()){
			cout << s.top();
			s.pop();
		}

		cout << ' ';
		
	}
}
