#include <iostream>
#include <cstring>
using namespace std;


int dfs(bool* alphabets, string* words, int wordcnt, 
		int alpha_learned, int learnable, int idx){
	if (alpha_learned == learnable){
		int cnt = 0;
		for (int i = 0; i < wordcnt; i++){
			string s = words[i];
			bool can_learn = true;
			int strlen = s.size();
			for (int c = 0; c < strlen; c++){
				if (alphabets[s[c] - 'a'] == false){
					can_learn = false;
					break;
				} 
			}
			if (can_learn) {
				cnt++;
			}
		}
		return cnt;
	} else if (alpha_learned > learnable){
		return 0;
	}
	
	int max_learn = 0;
	for(int i = idx; i < 26; i++){
		int val;
		if(alphabets[i] == false){
			alphabets[i] = true;
			val = dfs(alphabets, words, wordcnt, alpha_learned+1, learnable, i+1);
			if(val > max_learn){
				max_learn = val;
			}
			alphabets[i] = false;
		}
	
	}
	return max_learn;
}

int main(void){
	int N, K;
	cin >> N >> K;
	bool * alphabets = new bool[26];
	memset(alphabets, 0, 26);
	alphabets['a' - 'a'] = 1;
	alphabets['c' - 'a'] = 1;
	alphabets['i' - 'a'] = 1;
	alphabets['n' - 'a'] = 1;
	alphabets['t' - 'a'] = 1;

	string * words = new string[N];
	
	for(int i = 0; i < N; i ++){
		string s;
		cin >> s;
		words[i] = s;
	}
	
	int alpha_learned = 5;
	int answer;
	int idx = 0;
	
	if( K >= 5 ) {
		answer = dfs(alphabets, words, N, alpha_learned, K, idx);
	} else {
		answer = 0;
	}
	cout << answer << endl;
	delete alphabets;
	
}