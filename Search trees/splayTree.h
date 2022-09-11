#include "binaryTree.h"

using namespace std;

class SplayTree: public BinaryTree {
	private:
		Node* balance(Node* t,const int k){
			if(t != NULL and t->key != k){		
				if(k < t->key){
					if(t->l == NULL)
						return t;

					//casos: L->R, L->L
					if(k > t->l->key){		
						t = zig_zag(t, k, 'r');
					}
					else{				
						t = zig_zig(t, k, 'r');
					}
					
					if(t->l == NULL)
						return t;
					return finishZig(t ,'r');
				}
				else{
					if(t->r == NULL)
						return t;
					
					//casos: R->L, R->R
					if(k > t->r->key){			
						t = zig_zig(t, k, 'l');
					}
					else{						
						t = zig_zag(t, k, 'l');
					}

					return finishZig(t ,'l');
				}
			}
			return t;
		}
		Node* finishZig(Node* t, const char side){
			if(side == 'l' and t-> r!= NULL){
				return leftRotation(t);
			}
			else if(side == 'r' and t-> l!= NULL){
				return rightRotation(t);
			}
			return t;
		}
		Node* zig_zig(Node* t, const int k, const char side){
			if(side == 'l'){
				t->r->r = balance(t->r->r,k);
				t = leftRotation(t);
			}
			else {
				t->l->l = balance(t->l->l, k);
				t = rightRotation(t);
			}
			return t;
		}
		Node* zig_zag(Node* t, const int k, const char side){
			if(side == 'r'){
				t->l->r = balance(t->l->r,k);
					if (t->l->r != NULL)
						t->l = leftRotation(t->l);
			}
			else {
				t->r->l = balance(t->r->l, k);
					if (t->r->l != NULL)
						t->r = rightRotation(t->r);
			}
			return t;
		}
	public: 
		SplayTree(){}

		void insert(int k){
			createNode(k);
			root = balance(root, k);
		} 	
		bool searchDebug(int k){
			cerr<<"start of search: "<<k<<endl;
			printBT(root);
			Node *t = root;
			root = balance(root, k);
			cerr<<endl;
			printBT(root);
			return (root->key == k )? true : false;
		}	
		bool search(int k){
			Node *t = root;
			root = balance(root, k);
			return (root->key == k )? true : false;
		}
};