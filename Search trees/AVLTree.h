#include "binaryTree.h"

using namespace std;

class AVLNode: public Node {
	public:
		AVLNode* l = NULL;
		AVLNode* r = NULL; 
		int altura = 0; 
		int factor = 0;
};

class AVLTree: public BinaryTree {
	private:
		int mysize = 0;
		void calcularAltura(AVLNode* recorrido);
		void calcularFactor(AVLNode* recorrido);
		void balancear(AVLNode* recorrido, AVLNode* padre);
		void leftRotation(AVLNode* recorrido, AVLNode* padre);
		void rightRotation(AVLNode* recorrido, AVLNode* padre);
		void insertRecursivo(int elementoInsertado, AVLNode* recorrido, AVLNode* padre);
		bool empty();
	public:
		void insert(int elementoInsertado);
};