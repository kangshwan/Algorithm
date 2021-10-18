#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class ArrayStack{
	private:
		int* array;
		int size = 5;
		int idx = 0;
	public:
		ArrayStack(){
			array = (int*) malloc (sizeof(int)*size);
		}
	
		void push(int x){
			if(idx >= size){
				// size up 이 아닌 stack is full 해도 좋습니다.
				cout << "size up" << endl;
				size *= 2;
				array = (int*)realloc(array, sizeof(int)*size);
			}
			array[idx++] = x;
		}
		
		int pop(){
			idx--;
			if(idx < 0){
				idx = 0;
				cout <<  "stack is empty" << endl;
			}
			else
				return array[idx];
		}
		
		void free(){
			std::free(array);
		}
		
		bool empty(){
			return idx == 0;
		}
		
};

class ArrayQueue{
	private:
		int* array;
		int size = 5;
		int front = 0;
		int rear = 0;
	public:
		ArrayQueue(){
			array = (int*) malloc (sizeof(int)*size);
		}
		
		int pop(){
			int r_val = array[front++];
			if(front > rear){
				front = 0;
				rear = 0;
				cout << "queue is empty" << endl;
			}
			else
				return r_val;
		}
		
		void push(int x){
			if(front > size/2){
				cout << "reallocate" << endl;
				int *temp = (int*)malloc(sizeof(int)*size);
				int idx = 0;
				while(front != rear){
					temp[idx++] = pop();
				}
				front = 0;
				rear = idx;
				array = temp;
				
			}
			else if(rear >= size){
				
				cout << "size up" << endl;
				size *= 2;
				array = (int*)realloc(array, sizeof(int)*size);
			}
			
			array[rear++] = x;
		}
		
		
		void free(){
			std::free(array);
		}
		
		bool empty(){
			return front==rear;
		}
};

int main(){
	cout << "Stack Test, push 3,2,4,6,9,7,1,8" << endl;
	ArrayStack stack;
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
	stack.free();
	
	cout << endl << "Queue Test, push 3,2,4,6,9" << endl;
	ArrayQueue queue;
	
	queue.push(3);
	queue.push(2);
	queue.push(4);
	queue.push(6);
	queue.push(9);
	cout << "and pop 3 element to see reallocation"<<endl;
	cout<<queue.pop()<<" ";
	cout<<queue.pop()<<" ";
	cout<<queue.pop()<<endl;
	cout << "then push 7,1,8,10,37"<<endl;
	queue.push(7);
	queue.push(1);
	queue.push(8);
	queue.push(10);
	queue.push(37);
	
	while(!queue.empty()){
		cout << queue.pop() << " ";
	}

}
