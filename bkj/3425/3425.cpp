#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#define MAXNUM 1000000000
#define ll long long

using namespace std;
int main(void){
	
	while(1){
		bool terminate = false;
		vector <string> commands;
		vector <ll> numbers;
		
		while(1){
			string command;
			cin >> command;
			
			if (command == "QUIT"){
				terminate = true;
				break;
			}
		
            commands.push_back(command);	
			if (command == "END"){
				break;
			}
		}
		
		if(terminate){
			break;
		}
		
		ll N;
		cin >> N;
		for(ll i = 0; i < N; i++){
			ll tmp;
			cin >> tmp;
			numbers.push_back(tmp);
		}
		
		vector<ll>::iterator it;
		for (it = numbers.begin(); it != numbers.end(); it++){
			stack <ll> s;
			s.push(*it);
			
			vector<string>::iterator c = commands.begin();
			bool error = false;
			while(1){
				string command  = *c;
				if (command == "END"){
					break;
				} 
				
				switch(command[0]){
					case 'N':{
						c++;
						command = *c;
						ll X = atoi(command.c_str());
						s.push(X);
						break;
					}
					case 'P':{
						if (s.empty()){
							error = true;
							break;
						}
						s.pop();
						break;
					}
					case 'I':{
						ll tmp;
						tmp = s.top();
						s.pop();
						s.push(-tmp);
						break;
					}
					case 'D':{
						if(command[1] == 'U'){
							ll tmp = s.top();
							s.push(tmp);
						} else if (command[1] == 'I'){
							if (s.size() < 2) {
								error = true;
								break;
							} else {
								ll n1, n2;
								n1 = s.top();
								s.pop();
								n2 = s.top();
								s.pop();
								if( n1 == 0 ){
									error = true;
									break;
								} else {
									ll to_push;
                                    to_push = n1*n2>0?abs(n2)/abs(n1): -1*abs(n2)/abs(n1);
									s.push(to_push);
								}
							}
						}
						break;
					}
					case 'S':{
						if (s.size() < 2) {
							error = true;
							break;
						} else {
							ll n1, n2;
							n1 = s.top();
							s.pop();
							n2 = s.top();
							s.pop();
							if(command[1] == 'W'){
								s.push(n1);
								s.push(n2);
							} else if(command[1] == 'U'){
								if (abs(n2-n1) > MAXNUM){
									error = true;
									break;
								}
								s.push(n2-n1);
							}
						}
						break;
					}
					case 'A':{
						if (s.size() < 2) {
							error = true;
							break;
						} else {
							ll n1, n2;
							n1 = s.top();
							s.pop();
							n2 = s.top();
							s.pop();
							if(abs(n1 + n2) > MAXNUM){
								error = true;
								break;
							}
							s.push(n1+n2);
						}
						break;
					}
					case 'M':{
						if (s.size() < 2) {
							error = true;
							break;
						} else {
							ll n1, n2;
							n1 = s.top();
							s.pop();
							n2 = s.top();
							s.pop();
                            if(command[1] == 'U'){
							    if( abs(n1*n2) > MAXNUM ){
								    error = true;
								    break;
							    } else {
								    s.push(n1*n2);	
							    }
                            } else if(command[1] == 'O'){
							    if( n1 == 0 ){
								    error = true;
								    break;
							    } else {
								    s.push(n2%n1);	
							    }
                            }
						}
						break;
					}
				}
				
				if(error){
					break;
				}
				
				c++;
			}
			
			if (error || s.size() != 1){
				cout << "ERROR" << endl;
			} else {
				cout << s.top() << endl;
			}
		}
	
        cout << endl;	
	}
	
}
