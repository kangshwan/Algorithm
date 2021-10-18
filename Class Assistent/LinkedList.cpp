#include <iostream>
#include <string>

using namespace std;

struct Node{
	int data;
	struct Node* next = nullptr;
	struct Node* prev = nullptr;
};

class SinglyLinkedList{
	private:
		struct Node* head = nullptr;
	public:
		
		void appendFirst(int x){
			struct Node* new_node = new Node;
			new_node -> data = x;
			if(head == nullptr){
				head = new_node;
				return;
			}
			new_node -> next = head;
			head = new_node;
		}
		
		void appendLast(int x){
			struct Node* new_node = new Node;
			new_node -> data = x;
			struct Node* tmp = head;
			while(tmp->next != nullptr){
				tmp = tmp->next;
			}
			tmp->next = new_node;
		}
		
		void showList(){
			struct Node* cur = head;
			while(cur != nullptr){
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << endl;
		}	
		
		struct Node* findNode(int x){
			struct Node* tmp = head;
			while(tmp != nullptr){
				if(tmp->data == x){
					return tmp;
				}
				tmp->next;
			}
			return nullptr;
			
		}

		void deleteNode(int x){
			struct Node* cur = head;
			struct Node* prev = cur;
			
			while(cur != nullptr){
				if(cur->data == x){
					break;
				}
				prev = cur;
				cur = cur->next;
			}
			
			if(cur == nullptr){
				cout << "Node not found" << endl;
				return;
			}
			
			if(cur == prev){
				head = cur->next;
			}else{
				prev->next = cur->next;
			}
			cout << "Node deleted" << endl; 
		}
	
};
class DoublyLinkedList{
	private:
		struct Node* head = nullptr;
		struct Node* tail = nullptr;
	public:
		void appendFirst(int x){
			struct Node* new_node = new Node;
			new_node->data = x;
			
			if(head==nullptr){
				head=tail=new_node;
				return;
			}
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
			
		}
		
		void appendLast(int x){
			struct Node* new_node = new Node;
			new_node->data = x;
			
			if(head == nullptr){
				head = tail = new_node;
				return;
			}
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		void showList(){
			struct Node* cur = head;
			while(cur != nullptr){
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << endl;
		}
		
		struct Node* findNode(int x){
			struct Node* tmp = head;
			while(tmp != nullptr){
				if(tmp->data == x){
					return tmp;
				}
				tmp=tmp->next;
			}
			return nullptr;
			
		}
		
		void deleteNode(int x){
			struct Node* found = findNode(x);
			if(found == nullptr){
				cout << "Node not found" << endl;
				return;
			}
			if(found == head){
				head = found->next;
				found->next->prev = nullptr;
			}else if(found == tail){
				tail = found->prev;
				found->prev->next = nullptr;
			}else{
				found->prev->next = found->next;
				found->next->prev = found->prev;
			}
			cout << "Node deleted" << endl; 
		}
};

int main(){
	cout << "singly linked list" << endl;
	SinglyLinkedList l1;
	cout << "append First 1 2 3" << endl;
	cout << "append Last 4 5 6" << endl<<endl;
	l1.appendFirst(1);
	l1.appendFirst(2);
	l1.appendFirst(3);
	l1.appendLast(4);
	l1.appendLast(5);
	l1.appendLast(6);
	cout << "show List: ";
	l1.showList();
	cout << "delete data 4" << endl;
	l1.deleteNode(4);
	cout << "show List: ";
	l1.showList();
	cout << "delete data 8" << endl;
	l1.deleteNode(8);
	
	cout << endl << "doubly linked list" << endl;
	DoublyLinkedList l2;
	cout << "append First 1 2 3" << endl;
	cout << "append Last 4 5 6" << endl<<endl;;
	l2.appendFirst(1);
	l2.appendFirst(2);
	l2.appendFirst(3);
	l2.appendLast(4);
	l2.appendLast(5);
	l2.appendLast(6);
	cout << "show List: ";
	l2.showList();
	cout << "delete data 4" << endl;

	l2.deleteNode(4);
	cout << "show List: ";
	l2.showList();
	cout << "delete data 8" << endl;
	l2.deleteNode(8);
}
