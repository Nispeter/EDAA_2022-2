#include <iostream>

using namespace std;

class Node{
	public: 
		int key;
		Node* l = NULL;
		Node* r = NULL; 
		Node(int k):key(k){}
};

class BinaryTree {
	private: 
	public:
		Node* root = NULL;

		BinaryTree(int r): root(new Node (r)){}

		void inOrder(Node* n){
			if(n!= NULL){
				inOrder(n->l);
				cerr<<n->key<<" ";
				inOrder(n->r);
			}
		}

		void createNode(int k){
			Node *t = root;
			while(t != NULL){
				if(t->key > k){
					if(t->l != NULL){
						t = t->l;
						continue;
					}
					t->l = new Node(k);
					break;
				}
				if(t->r != NULL){
					t = t->r;
					continue;
				}
				t->r = new Node(k);
				break;
			}
		}

		void printTree(){
			inOrder(root);
		}

};


/*
OBSEVACIONES: 
1->- recordar que este arbol binario debe heredar 
todas sus funciones a los otros arboles (por pauta)
2->- tiene funcionalidad de set por lo que no existiran
valores con la misma clave (por pauta)
*/



