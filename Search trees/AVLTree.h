#include "binaryTree.h"

using namespace std;

class AVLNode: public Node {
	public:
		int altura = 0; 
		int factor = 0;
};

class AVLTree: public BinaryTree {
	private:
		int mysize = 0;
		void calcularAltura(Node* recorrido);
		void calcularFactor(Node* recorrido);
		void balancear(Node* recorrido, Node* padre);
		void leftRotation(Node* recorrido, Node* padre);
		void rightRotation(Node* recorrido, Node* padre);
		void insertRecursivo(int elementoInsertado, Node* recorrido, Node* padre);
		bool empty();
	public:
		Node* head = NULL;
		void insert(int elementoInsertado);
};