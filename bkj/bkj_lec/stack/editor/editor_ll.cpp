#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
	T value;
	struct Node<T> *next = nullptr;
	struct Node<T> *prev = nullptr;
};

template <typename T>
class Editor
{
private:
	Node<T> *head;
	Node<T> *cur;
	int size;

public:
	Editor(){
		Node<T> *dummyhead = new Node<T>;
		Node<T> *dummytail = new Node<T>; 
    dummyhead->next = dummytail;
    dummyhead->prev = nullptr;
    dummytail->next = nullptr;
    dummytail->prev = dummyhead;
		size = 0;
		
	}

	Editor(string initstr){

		Node<T> *dummyhead = new Node<T>;
		Node<T> *dummytail = new Node<T>;
    dummyhead->next = dummytail;
    dummyhead->prev = nullptr;
    dummytail->next = nullptr;
    dummytail->prev = dummyhead;

    head = dummyhead;
    cur = dummyhead;

		for(string::iterator it = initstr.begin(); it != initstr.end(); ++it){
			P(*it);
		}

		size = initstr.length();
	}
	
	void P(T _value) // insert text
	{
		Node<T> *node = new Node<T>;
		size++;

		node->value = _value;
		node->next = cur->next;
		cur->next->prev = node;
		node->prev = cur;			
		cur->next = node;
		cur = node;
	}

	void L() // go to left
	{
		if(cur == head){
			return;
		}
		cur = cur->prev;
	}

	void D() // go to right
	{
		if(cur->next->next == nullptr){
			return;	
		}
		cur = cur->next;
	}

	void B() // delete text
	{
		Node<T> *ptr = cur;

		if(ptr == head){
			return;
		} else {
			size--;
			Node<T> * next;
			Node<T> * tmp;
			tmp = cur;
			next = cur->next;

			cur = cur->prev;
			cur->next = next;
			next->prev = cur;
			delete tmp;
		}
	}

	void printText(){
		Node<T> *n = head->next;
		while(true){
      if(n->next == nullptr){
        break;
      }
			cout << n->value;
      if(n == cur){
       // cout << "|";
      }
			n = n->next;
		}
    cout << endl;
	}

	void DeleteList()
	{
		Node <T> *ptr = cur;
		while(ptr != nullptr){
			cur = ptr->next;
			delete ptr;
			ptr = cur;
		}

		delete cur;
		size = 0;
		cout << "delete list" << endl;
	}

};

int main(void)
{

  string str;
  int N;
  cin >> str;
  cin >> N;

  Editor<char> e(str);
  //e.printText();
  while(N--){
    char command;
    cin >> command;

    if(command == 'L'){
      e.L();
    } else if(command == 'D') {
      e.D();
    } else if(command == 'B') {
      e.B();
    } else if(command == 'P') {
      char newchar;
      cin >> newchar;
      e.P(newchar);
    } else {
      printf("ERROR: %c\n", command);
    }
  }
  e.printText();

}

