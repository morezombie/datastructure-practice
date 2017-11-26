//计算一棵树的宽度

#include <stdio.h>

class Node{
public:
	typedef int value_t;
	value_t GetValue() {return m_value;}
	Node* GetLeft() {return m_left;}
	Node* GetRight() {return m_right;}

	void SetValue(value_t v) {m_value=v;}
	void SetLeft(Node* n) {m_left = n;}
	void SetRight(Node* n) {m_right = n;}

	Node(value_t v):m_value(v),m_left(NULL),m_right(NULL){}
	~Node(){
		if(m_left) delete m_left;
		if(m_right) delete m_right;
	}
private:
	value_t m_value;
	Node* m_left;
	Node* m_right;
};

class Tree{
private:
	Node* m_list;
	int size;
public:
	Tree():m_list(NULL),size(0){}
	~Tree() {if(m_list) delete m_list;}
	Node* find(Node::value_t, Node*);
	Node* insert(Node::value_t v, Node* father);
	Node* findmin(Node*);
	Node* findmax(Node*);
	int GetSize(){return size;}
	Node* GetTreeRoot() {return m_list;}
	void SetTreeRoot(Node* r) {m_list = r;}
	void Tranverse(Node*, int, int&);
};

Node* Tree::find(Node::value_t v, Node* t) {
	if(!t) return insert(v, t);
	if(t->GetValue()==v) { 
		return t;
	}else if(t->GetValue()>v) { 
		if(t->GetLeft()) return find(v, t->GetLeft());
		else return insert(v, t);
	}else{  
		if(t->GetRight()) return find(v, t->GetRight());
		else return insert(v, t);
	}
}

Node* Tree::insert(Node::value_t v, Node* father) {
	if(!father) {
		father = new Node(v);
		return father;
	}else {
		Node* son = new Node(v);
		if(father->GetValue()>v) {
			printf("insert leftson %d, father %d\n",v,father->GetValue());
			father->SetLeft(son);
		}else {
			printf("insert rightson %d, father %d\n",v,father->GetValue());
			father->SetRight(son);
		}
		return son;
	}
}


Node* Tree::findmin(Node* r) {
	if(!r) return r;
	if(r->GetLeft()) return findmin(r->GetLeft());
	else return r;
}

Node* Tree::findmax(Node* r) {
	if(!r) return r;
	if(r->GetRight()) return findmax(r->GetRight());
	else return r;
}

void Tree::Tranverse(Node* r, int t_type, int& num) {
	if(t_type==0){//中序遍历
		if(!r) return ;
		Tranverse(r->GetLeft(),t_type,num);
		printf("node[%d]=%d\n",num++,r->GetValue());
		Tranverse(r->GetRight(),t_type,num);
	}
	else if(t_type==1){//先序遍历
		if(!r) return ;
		printf("node[%d]=%d\n",num++,r->GetValue());
		Tranverse(r->GetLeft(),t_type,num);
		Tranverse(r->GetRight(),t_type,num);
	}
	else if(t_type==2){//后序遍历
		if(!r) return ;
		Tranverse(r->GetLeft(),t_type,num);
		Tranverse(r->GetRight(),t_type,num);
		printf("node[%d]=%d\n",num++,r->GetValue());
	}
}

int main(int argc, char** argv) {
	
	Node::value_t input[]={233,142,15,198,238,62,357,274};
	Tree tree;
	int tree_width=0;
	Node* root = new Node(input[0]);
	tree.SetTreeRoot(root);
	
	for(int i=1;i<sizeof(input)/sizeof(Node::value_t);i++){
		tree.find(input[i],root);
	}
	tree.Tranverse(root,0,tree_width);
	printf("tree width=%d\n",tree_width);
	tree_width = 0;
	tree.Tranverse(root,1,tree_width);
	printf("tree width=%d\n",tree_width);
	tree_width = 0;
	tree.Tranverse(root,2,tree_width);
	printf("tree width=%d\n",tree_width);

	return 0;
}
