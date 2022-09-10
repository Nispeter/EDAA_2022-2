#include <bits/stdc++.h>			//no me funen estoy en el lab y tengo tiempo limitado 
#include "splayTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BinaryTree b;
	b.createNode(-1);
	b.createNode(-3);
	b.createNode(-7);
	b.createNode(3);
	b.createNode(6);
	b.createNode(2);
	b.createNode(8);
	b.createNode(11);
	b.createNode(9);
	b.createNode(-2);
	//b.printTree(b.root);
	b.root = b.leftRotation(b.root);
	//b.root = b.rightRotation(b.root);
	//b.printTree(b.root);
	b.printBT(b.root);
	return 0;
}


