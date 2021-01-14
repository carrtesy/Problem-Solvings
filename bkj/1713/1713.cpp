#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Person{
public:
	int id;
	int cnt;
	int timestamp;

    Person(){
        this->id  = -1;
        this->cnt = -1;
        this->timestamp = -1;
    }

    Person(int id, int cnt, int timestamp)
    {
        this->id  = id;
        this->cnt = cnt;
        this->timestamp = timestamp;
    }

    bool operator <(Person &p){
        if (this->id == -1){
            return this->id < p.id;
        }
        if(this->cnt != p.cnt){
            return this->cnt < p.cnt;
        } else{
            return this->timestamp < p.timestamp;
        }
    }
};

int main(void){
	int N, L;
	cin >> N >> L;
    vector<Person> 
    Person arr[101];
	
	for(int i = 0; i < L; i++){
	    int stid;
        cin >> stid;
        Person p = arr[stid];
        cout << stid;
        if(p.id == -1){
            cout << "h" << endl;
            arr[stid].id = stid;
            arr[stid].cnt = 1;
            arr[stid].timestamp = i;
        } else {
            cout <<"t" <<endl;
            arr[stid].cnt++;
        }
    }

    make_heap(arr, arr+101);
    
    for (int i = 0 ; i < N; i++){
        cout <<"HEAP" <<endl;
        cout << arr[0].id << endl;  
        for(int i = 0; i < 11; i++){
            cout << arr[i].id << ' '<< arr[i].cnt << ' '<<arr[i].timestamp  << endl;
        }
        pop_heap(arr, arr+101);
    }
}
