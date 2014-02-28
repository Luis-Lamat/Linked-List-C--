#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

int main()
{

	LinkedList<int> *lista1 = new LinkedList<int>();

	lista1->addFirst(10);
	lista1->addFirst(100);
	lista1->addFirst(1000);
	lista1->print();
	//cout << lista1;
	cout << endl;

	LinkedList<string> *lista2 = new LinkedList<string>();

	lista2->addFirst("estas?");
	lista2->addFirst("como");
	lista2->addFirst("Luis");
	lista2->addFirst("Hola");
	lista2->print();
	//lista2->change(0,3);
	//cout << lista2;
	lista2->reverse();
	lista2->print();
	//cout << lista2;

	cout << endl;

	LinkedList<int> *lista3 = new LinkedList<int>();

	lista3->addFirst(1);
	lista3->addFirst(2);
	lista3->addFirst(3);
	lista3->print();
	//cout << lista3;

	cout << endl;

	LinkedList<int> *lista4 = new LinkedList<int>();

	lista4->addFirst(1);
	lista4->addFirst(2);
	lista4->addFirst(3);
	lista4->print();
	//cout << lista4;

	cout << endl;


	if (*lista3 == *lista4)
		cout << "Si son iguales!" << endl;
	else
		cout << "Fue falso" <<endl;

	lista3->reverse();
	lista3->print();
	lista3->addFirst(0);
	lista3->print();
	lista3->shift(5);
	lista3->print();
	//cout << lista3;

	lista4->deleteFirst();
	lista4->print();
	lista4->shift(1);
	lista4->print();

	delete lista1;
	delete lista2;
	delete lista3;
	delete lista4;


	return 0;
}