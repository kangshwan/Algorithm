#include <iostream>

using namespace std;

struct node{
	node* left;
	node* right;
	node* parent;
	node* child;
	int value;
	int rank;
	bool loser;
};

class FibonacciHeap{
	private:
		node* heap;
	public:
		FibonacciHeap(){
			heap = NULL;
		}
		node* makeSingleNode(int value){
			node* n = new node;
			n->left = n;
			n->right = n;
			n->parent = NULL;
			n->child = NULL;
			n->value = value;
			n->rank = 0;
			n->loser = false;
		}
		
		node* appendRoot(node* b){
			//왠지 필요할것같은 느낌이 강하게 듭니다. 
			node* end = heap->left;
			end->right = b;
			b->left = end;
			heap->left = b;
			b->right = heap;
			return heap;
		}
		node* push(int value){
			node* tmp = makeSingleNode(value);
			appendRoot(tmp);
			return tmp;
		}
		
		node* cut(node* n){
			node* parent = n->parent;
			
		}
		node* decreaseKey(node* n, int changeVal){
			if(n->value < changeVal) return heap;
			if(n->parent == NULL){
				n->value = changeVal;
				return heap;
			}else if(n->parent > changeVal){
				n->value = changeVal;
				return heap;
			}
			cut(n);
			
			
			
		}
};

int main(){
	FibonacciHeap heap;
}
