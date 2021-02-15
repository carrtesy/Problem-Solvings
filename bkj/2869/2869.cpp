#include <iostream>

using namespace std;
int main(void){
	int A, B, V;
	cin >> A >> B >> V;
	int x = (V-A) % (A-B) ? (V-A)/(A-B) + 2: (V-A)/(A-B) + 1;
	cout << x << '\n';
}
