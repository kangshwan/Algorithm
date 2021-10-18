#include <iostream>
#include <string>

using namespace std;

struct Node{
	int data;
	struct Node* next = nullptr;
};


class LinkedListStack{
	private:
		struct Node* head = nullptr;
	public:
		void push(int x){
			struct Node* new_node = new Node;
			new_node->data = x;
			if(head == nullptr){
				head = new_node;
				return;
			}
			new_node->next = head;
			head = new_node;
		}
		
		int pop(){
			if(head != nullptr){
				int r_val = head->data;
				head = head->next;
				return r_val;
			}
		}
		
		bool empty(){
			return head == nullptr;
		}
		
};

class LinkedListQueue{
	private:
		struct Node* head = nullptr;
		struct Node* tail = nullptr;
	public:
		void push(int x){
			struct Node* new_node = new Node;
			new_node->data = x;
			
			if(head == nullptr){
				head = tail = new_node;
				return;
			}
			tail->next = new_node;
			tail = new_node;
		};
		
		int pop(){
			
			if(head != nullptr){
				int r_val = head->data;
				head = head->next;
				return r_val;
			}
			
		};
		
		bool empty(){
			return head == nullptr;
		}
		
};

int main(){
	cout << "Stack Test" << endl;
	
	LinkedListStack stack;
	
	stack.push(3);
	stack.push(2);
	stack.push(4);
	stack.push(6);
	stack.push(9);
	stack.push(7);
	stack.push(1);
	stack.push(8);
	
	while(!stack.empty()){
		cout << stack.pop() << " ";
	}
	
	cout << endl << "Queue Test" << endl;
	
	LinkedListQueue queue;
	
	queue.push(3);
	queue.push(2);
	queue.push(4);
	queue.push(6);
	queue.push(9);
	queue.push(7);
	queue.push(1);
	queue.push(8);
	while(!queue.empty()){
		cout << queue.pop() << " ";
	}
	
}
