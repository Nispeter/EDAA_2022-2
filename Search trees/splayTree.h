#include "binaryTree.h"

using namespace std;

class SplayTree: public BinaryTree {
	private:
		Node* balance(Node* next, int k){
			if(next->key == k or next == NULL)
				return next;
			if(k < next->key){

			}
			if(k > next->key){

			}
		}	
		void zig_zig(){}
		void zig_zag(){}	
	public: 
		SplayTree(){}

		void insert(int k){
			createNode(k);
		} 	
		bool search(int k){
			Node *t = root;
			return (balance(t, k) == NULL)? false : true;
		}	
};