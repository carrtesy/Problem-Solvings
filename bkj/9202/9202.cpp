#include <iostream>
#include <string>

using namespace std;

typedef struct _Node {
    bool isEnd;
    bool isHit;
    char c;
    _Node** childs;
} Node;

class Trie{
    Node root;
public:
    Trie(){
        root = {};
        root.isEnd = false;
        root.isHit = false;
        root.childs = new Node*[26];
    }

    void _printTrie(Node n){
        for(int i = 0; i < 26; i++){
            if(n.childs[i]){
                cout << n.childs[i]->c << endl;
                _printTrie(*n.childs[i]);
            }
        }
    }

    void printTrie(){
        _printTrie(root);
    }

    Node* createNode(char c){
        Node* n = {};
        n->isEnd = false;
        n->isHit = false;
        n->c = c;
        n->childs = new Node*[26];
        return n;
    }

    void insert(string s){
        int l = s.size();
        for(int i = 0; i < l; i++){
            char c = s[i];
            Node cur = root;
            int wordidx = c - 'A';
            if(!cur.childs[wordidx]){
                Node *newNode = new Node;
                newNode->isEnd = false;
                newNode->isHit = false;
                newNode->c = c;
                newNode->childs = new Node*[26];
                cur.childs[wordidx] = newNode;   
            }
            cur = *cur.childs[wordidx];
            
            if(i == l-1){
                cur.isEnd = true;    
            }
        }
    }
    
};

int main(void){
    int w, b;

    cin >> w;
    string * words = new string[w];

    for(int i = 0; i < w; i++) cin >> words[i];
    for(int i = 0; i < w; i++) cout << words[i] << endl; 
    
    Trie trie;
    for(int i = 0; i < w; i++){
        trie.insert(words[i]);
        trie.printTrie();
    }
    
    cin >> b;
    cout << b << endl;

    while(b--){
        char** board = new char*[4];
        for(int r = 0; r < 4; r++){
            board[r] = new char[4];
            string tmp;
            cin >> tmp;
            for(int c = 0; c < 4; c++){
                board[r][c] = tmp[c];
            }
        }

    
        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                cout << board[r][c] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        delete board;
    }  
}
