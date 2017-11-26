//实现一个堆，最小值为根

#include <stdio.h>

typedef int key_t;
typedef int value_t;

class Node {
public:
	key_t key;
	int count;
	bool isEmpty() { return count==0;}
	Node():count(0){}
private:
	value_t value;

};

class Heap {

private:
	int capability;
	Node* list; 
	int size;
public:
	Heap(int cap):capability(cap) {
		list = new Node[cap];
		memset(list, 0, cap*sizeof(Node));
	}
	~Heap(){
		delete[] list;
	}
	void insert(Node n, Node* r);
	void deleteNode(key_t k);
	Node* end(Node* r);
	int find(key_t k, Node* r);
	Node* minSon(Node*);
	int size() { return size; }
};

Node* Heap::end(Node* r) {
	if(r->isEmpty())
		return r;
	Node * left = (r-list)*2;
	if(left->isEmpty()) 
		return left;
	else
		end(left);
	Node * right = 2*(r-list)+1;
	if(right->isEmpty()) 
		return right;
	else
		end(right);

}

void Heap::insert(Node n, Node* r) {

	Node* pos = find(n, r);
	if(pos) {
		pos->count++;
		size++;
		return;
	} 
		
	Node *blank = end(r);
	Node *father;	
	while(n.key < (father = (blank-list)/2)->key ) {

		*blank = *father;
		blank = father;	
	}
	*blank = n;
	size++;

}

Node* Heap::find(key_t k) {
	if(r->isEmpty()) {
		return NULL;
	}
	if(r->key == k) {
		return r;
	}
	Node* left = (r-list)/2;
	Node* right = left + 1;
	find(k, left);
	find(k, right);
}

Node* Heap::minSon(Node* father) {
	Node* left = (father-list)/2;
	Node* right = left+1;
	if(left->isEmpty()) 
		return NULL;
	else if(right->isEmpty())
		return left;
	else
		return left->key<right->key?left:right;
}

void Heap::deleteNode(key_t k) {
	Node* pos = find(k, list);
	if(pos->isEmpty()) 
		return;
	if(pos->count > 1) {
		pos->count--;
		return;
	}
	else {
		Node* son;
		Node* end_node = end(list);
		while(end_node->key > (son = minSon(pos))->key ) {
			*pos = *son;
			pos = son;
		}
		*pos = *end_node;
		end_node->count = 0;
	}
}

int main(int argc, char** argv) {

	return 0;
}
