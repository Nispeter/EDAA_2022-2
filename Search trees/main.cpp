#include <bits/stdc++.h>			//no me funen estoy en el lab y tengo tiempo limitado 
#include "splayTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BinaryTree BT(10);
	BT.createNode(5);
	BT.createNode(2);
	BT.createNode(21);
	BT.createNode(11);
	BT.createNode(13);

	BT.printTree();
	return 0;
}


