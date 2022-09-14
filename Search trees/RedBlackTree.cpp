#include "RedBlackTree.h"

using namespace std;

#define red -1
#define black 1

void RedBlackTree::left_rotate(Node *n){
	Node *n2 = n->r;
	Node *n3 = n->r->l;
	//actualizamos padre del elemento 2
	if(n == root){//reemplaza root
		parent[n2] == n2;
		root = n2;
	}
	else if(parent[n]->l == n){
		parent[n2] = parent[n];
		parent[n]->l = n2;
	}
	else{
		parent[n2] = parent[n];
		parent[n]->r = n2;
	} 
	//ejecutamos rotacion
	n2->l = n;
	n->r = n3;
	parent[n] = n2;
	parent[n3] = n;
}

void RedBlackTree::right_rotate(Node *n){
	Node *n2 = n->l;
	Node *n3 = n->l->r;
	//actualizamos padre del nodo 2
	if(n == root){//reemplaza root
		parent[n2] = n2;
		root = n2;
	}
	else if(parent[n]->l == n){
		parent[n2] = parent[n];
		parent[n]->l = n2;
	}
	else{
		parent[n2] = parent[n];
		parent[n]->r = n2;
	}
	//ejecutamos rotacion
	n2->r = n;
	n->l = n3;
	parent[n] = n2;
	parent[n3] = n;
}

void RedBlackTree::fixInsert(Node *n){//balanceamos el arbol
	if(n == root){//caso root
		color[n->key] = black;
		return;
	}
	while(color[parent[n]->key] == red){
		Node* uncle;
		Node* granp = parent[parent[n]];

		if(parent[n] != granp->l) uncle = granp->l;//determinamos nodo uncle
		else uncle = granp->r;

		//caso uncle rojo
		if(uncle != NULL and color[uncle->key] == red){
			color[granp->key] = red;
			color[parent[n]->key] = black;
			color[uncle->key] = black;
			n = granp;
			continue;
		}
		//casos black uncle
		//caso triangulo derecho
		else if(parent[n]->l == n and granp->r == parent[n]){
			Node *newn = parent[n];
			right_rotate(parent[n]);
			n= newn;
		}
		//caso triangulo izquierdo
		else if(parent[n]->r == n and granp->l == parent[n]){
			Node *newn = parent[n];
			left_rotate(parent[n]);
			n = newn;
		}
		//caso linea hacia la derecha
		if(parent[n]->r == n and granp->r == parent[n]){
			color[granp->key] = red;
			color[parent[n]->key] = black;
			left_rotate(granp);
		}
		else{//caso linea a la izquierda
			color[granp->key] = red;
			color[parent[n]->key] = black;
			right_rotate(granp);

		}

	}

}

Node* RedBlackTree::createNode(int k){//override
	if (size == 0){//primer nodo
		size++;
		root = new Node(k);
		parent[root] = root;
		return root;
	}
	Node *t = root;
	while(t != NULL){//encontramos lugar en el arbol e insertamos registrando padre
		if(t->key == k)return NULL;
		if(t->key > k){
			if(t->l != NULL){
				t = t->l;
				continue;
			}
			t->l = new Node(k);
			parent[t->l] = t;
			size++;
			return t->l;
		}
		if(t->r != NULL){
			t = t->r;
			continue;
		}
		t->r = new Node(k);
		parent[t->r] = t;
		size++;
		return t->r;
	}
	return NULL;
}

void RedBlackTree::insert(int k){
	Node *newN =  createNode(k);//creamos nodo
	if(newN == NULL)return;//ya existia nodo en set
	//establecemos como base colo rojo
	color[newN->key] = red;
	fixInsert(newN);
}

void RedBlackTree::printColors(const string& prefix, const Node* node, bool isLeft)
{//funcion de impresion
    if( node != nullptr )
    {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        string c;
        if(color[node->key] == 1)c = "b";
        else c = "r";
        cout << node->key <<" "<<c<< std::endl;

        printColors( prefix + (isLeft ? "│   " : "    "), node->r, true);
		printColors( prefix + (isLeft ? "│   " : "    "), node->l, false);
    }
}