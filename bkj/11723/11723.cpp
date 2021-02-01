#include <iostream>
#include <cstring>
using namespace std;

class Set{
public:
    bool elements[21];
    
    Set(){
        memset(elements, 0, 21);
    }

    void add(int x){
        elements[x] = true;
    }
    
    void remove(int x){
        elements[x] = false;
    }

    void toggle(int x){
        elements[x] = !elements[x];
    }

    void all(){
        memset(elements, 1, 21);
    }

    void empty(){
        memset(elements, 0, 21);
    }

    int check(int x){
        return elements[x];
    }
};


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin >> M;
    Set set;

    while(M--){
        string command;
        cin >> command;


        if(command[0] == 'a' && command[1] == 'l'){
            set.all();            
        } else if(command[0] == 'e'){
            set.empty();
        } else {
            int x;
            cin >> x;
            switch(command[0]){
                case 'a':{
                    set.add(x);
                    break;
                }
                case 'r':{
                    set.remove(x);
                    break;
                }
                case 'c':{
                    printf("%d\n", set.check(x));
                    break;
                }
                case 't':{
                    set.toggle(x);
                    break;
                }
            }
        }        
    }
}
