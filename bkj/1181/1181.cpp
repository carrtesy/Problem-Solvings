#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpword(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1.compare(s2) < 0;    
    } else {
        return s1.length() < s2.length();
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string *words = new string[N];
    for(int w = 0; w < N; w++) cin >> words[w];
    sort(words, words + N, cmpword);
    string tmp = words[0];
    cout << words[0] << '\n';
    for(int w = 0; w < N; w++) {
        if(words[w].compare(tmp) == 0) continue;
        cout << words[w] << '\n';
        tmp = words[w];
    }
}
