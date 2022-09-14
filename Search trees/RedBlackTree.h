#include "binaryTree.h"
#include <map>

#define red -1
#define black 1 

using namespace std;



class RedBlackTree: public BinaryTree {
	private:
		int size = 0;
		map<int,int> color;//mapa que determina el color de los nodos
		map<Node*,Node*> parent;//contiene relacion de padre e hijo entre nodos
		Node* createNode(int k);
		void fixInsert(Node *n);
		void right_rotate(Node *n);
		void left_rotate(Node *n);

	public: 
		void printColors(const string& prefix, const Node* node, bool isLeft);
		void insert(int k);
};