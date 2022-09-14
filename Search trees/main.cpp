#include <bits/stdc++.h>			//no me funen estoy en el lab y tengo tiempo limitado
//#include "splayTree.h"
#include "AVLTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	AVLTree b;
	b.insert(1);
	b.insert(33);
	b.insert(7);
	b.insert(3);
	b.insert(6);
	b.insert(2);
	b.insert(8);
	b.insert(11);
	b.insert(92);
	b.insert(27);
    b.insert(9);
    b.insert(3);
    b.insert(80);
    b.insert(98);
    b.insert(62);
    b.insert(21);
    b.insert(82);
    b.insert(111);
	b.printBT(b.root);
	cout << b.search(80000) << endl;

	return 0;
}


