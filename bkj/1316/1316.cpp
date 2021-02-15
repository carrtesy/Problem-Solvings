#include <iostream>
#include <cstring>
using namespace std;

bool isGroupWord(string s){
	bool alphabet[26];
	memset(alphabet, 0, 26);
	int len = s.length();
	int cur = 0;
	
	while(cur < len){
		char c = s[cur];
		if(alphabet[c - 'a']) return false;
		alphabet[c-'a'] = true;
		while(s[cur] == c) cur++;
	}
	return true;
}

int main(void){
	int N;
	cin >> N;
	int answer = 0;
	while(N--){
		string s;
		cin >> s;
		answer += isGroupWord(s);
	} 
	cout << answer << '\n';
}
