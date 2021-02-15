#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	cin >> s;
	
	int len = s.length();
	int cur = 0;
	int answer = 0;
	while(cur < len){
		switch(s[cur]){
			case 'c':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == '=' || s[cur+1] == '-') cur += 2;
				else cur++;
				break;
			}
			case 'd':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == '-') cur += 2;
				else if(s[cur+1] == 'z') {
					if(cur+2 >= len || s[cur+2] != '='){
						answer++;
						cur += 2;
					} else {
						cur += 3;
					}
				}
				else cur++;
				break;
			}
			case 'l':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == 'j') cur += 2;
				else cur++;
				break;
			}
			case 'n':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == 'j') cur += 2;
				else cur++;
				break;
			}
			case 's':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == '=') cur += 2;
				else cur++;
				break;
			}
			case 'z':{
				if(cur+1 >= len) cur++;
				else if(s[cur+1] == '=') cur += 2;
				else cur++;
				break;
			}
			default:{
				cur++;
				break;
			}
		}
		answer++;
	}
	
	cout << answer << '\n';
}
