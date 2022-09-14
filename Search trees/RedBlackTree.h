#include "binaryTree.h"

#define red -1
#define black 1 

using namespace std;



class RedBlackTree: public BinaryTree {
	private:
		int size = 0;
		map<int,int> color;//-1 es rojo y 1 es negro
		map<Node*,Node*> parent;

		void left_rotate(Node *n){
			Node *n2 = n->r;
			Node *n3 = n->r->l;
			if(n == root){
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
			n2->l = n;
			n->r = n3;
			parent[n] = n2;
			parent[n3] = n;
		}

		void right_rotate(Node *n){
			Node *n2 = n->l;
			Node *n3 = n->l->r;
			//determinamos el padre del nodo 2
			if(n == root){
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
			//determinamos el padre del resto de nodos
			n2->r = n;
			n->l = n3;
			parent[n] = n2;
			parent[n3] = n;
		}

		void fixInsert(Node *n){
			if(n == root){
				color[n->key] = black;
				return;
			}
			while(color[parent[n]->key] == red){
				Node* uncle;
				Node* granp = parent[parent[n]];

				if(parent[n] != granp->l) uncle = granp->l;
				else uncle = granp->r;


				//red uncle case
				if(uncle != NULL and color[uncle->key] == red){
					color[granp->key] = red;
					color[parent[n]->key] = black;
					color[uncle->key] = black;
					n = granp;
					continue;
				}
				//casos black uncle
				//right triangle case
				else if(parent[n]->l == n and granp->r == parent[n]){
					Node *newn = parent[n];
					right_rotate(parent[n]);
					n= newn;
				}
				//left triangle case
				else if(parent[n]->r == n and granp->l == parent[n]){
					Node *newn = parent[n];
					left_rotate(parent[n]);
					n = newn;
				}

				if(parent[n]->r == n and granp->r == parent[n]){
					color[granp->key] = red;
					color[parent[n]->key] = black;
					left_rotate(granp);
				}
				else{
					color[granp->key] = red;
					color[parent[n]->key] = black;
					right_rotate(granp);

				}

			}

		}

		Node *createNode(int k){//override
			if (size == 0){
				size++;
				root = new Node(k);
				parent[root] = root;
				return root;
			}
			Node *t = root;
			while(t != NULL){
				if(t->key == k)return NULL;
				if(t->key > k){
					if(t->l != NULL){
						t = t->l;
						continue;
					}
					t->l = new Node(k);
					parent[t->l] = t;
					return t->l;
				}
				if(t->r != NULL){
					t = t->r;
					continue;
				}
				t->r = new Node(k);
				parent[t->r] = t;
				return t->r;
			}
			size++;
		}
		
	public: 
		void insert(int k){
			Node *newN =  createNode(k);
			if(newN == NULL)return;
			color[newN->key] = red;
			fixInsert(newN);
		}

		void printColors(const string& prefix, const Node* node, bool isLeft)
		{
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

};
