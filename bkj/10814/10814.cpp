#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct info{
    int age;
    string name;
    int time;
};

bool cmp(info a, info b){
    if(a.age == b.age){
        return a.time < b.time;
    } else {
        return a.age < b.age;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    info* arr = new info[N];
    for(int i = 0; i < N; i++){
        info member;
        int age;
        string name;
        cin >> age >> name;
        member = {age, name, i};
        arr[i] = member;
    }

    sort(arr, arr+N, cmp);
    for(int i = 0; i < N; i++){
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }
}
