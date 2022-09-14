#include <bits/stdc++.h>			//no me funen estoy en el lab y tengo tiempo limitado 
#include "RedBlackTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	RedBlackTree b;
	b.insert(-1);
	b.printColors("", b.root, false);
	b.insert(-3);
	b.printColors("", b.root, false);
	b.insert(-7);
	b.printColors("", b.root, false);
	b.insert(3);
	b.printColors("", b.root, false);
	b.insert(6);
	b.printColors("", b.root, false);
	b.insert(2);
	b.printColors("", b.root, false);
	b.insert(8);
	b.printColors("", b.root, false);
	b.insert(11);
	b.printColors("", b.root, false);
	b.insert(9);
	b.printColors("", b.root, false);
	b.insert(-2);
	b.printColors("", b.root, false);
	b.insert(10);
	
	//b.printTree(b.root);
	//b.root = b.leftRotation(b.root);
	//b.root = b.rightRotation(b.root);
	//b.printTree(b.root);
	b.printBT(b.root);
	b.printColors("", b.root, false);
	return 0;
}


