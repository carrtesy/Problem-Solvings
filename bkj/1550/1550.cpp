#include <iostream>
#include <string>

using namespace std;
int main(void){
	string s;
	cin >> s;
	
	int ans = 0;
	int pow = 1;
	int strlen = s.size();
	
	for(int i = strlen-1; i >= 0; i--){
		char c = s[i];
		if ('0' <= c && c <= '9'){
			ans += ((c - '0') * pow);
		} else if ('A' <= c && c <= 'F'){
			ans += ((c - 'A' + 10) * pow);
		}
		pow <<= 4;
	}
	
	cout << ans << endl;
}
