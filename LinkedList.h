
#include "node.h"
using namespace std;

template <class T>

class LinkedList {

private:
    node<T> *head;
public:
	int length;
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(T d);
    void addLast(T d);
    bool add(T d, int index);
    T deleteFirst();
    T deleteLast();
    T deleteNode(int index);
    T setD(T d, int index);
    T getD(int index);
    int deleteAll();
    bool change(int index1, int index2);
    void reverse();
    //friend ostream& operator<<(ostream& os, LinkedList<T> &list);
    bool operator==(LinkedList<T> &list);
    void print();
};

template <typename T>
LinkedList<T>::LinkedList(){
	head = NULL;
	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	node<T> *aux = head;
	while (head != NULL){
		aux = aux->getNext();
		delete head;
		head = aux;
	}
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	return (head == NULL);
}

template <typename T>
void LinkedList<T>::addFirst(T d){
    node<T> *n = new node<T>(d, head);
    head = n;
    length++;
}

template <typename T>
void LinkedList<T>::addLast(T d){
	if (this->isEmpty())
		addFirst(d);
	else {
		node<T> *aux = head; //los dos apuntan al mismo

		while (aux->getNext()){ //para posicionarnos en el ultimo
			aux = aux->getNext();
		}
		node<T> *nuevo = new node<T>(d);
		aux->setNext(nuevo);
		length++;
	}
}

template <typename T>
bool LinkedList<T>::add(T d, int index){
	
	if (index > length-1 || index < 0)
		return false;

	if (index == 0)
		return addFirst(d);
	else if (index == length-1)
		return addLast(d);

	node<T> *aux = head, *aux2;
	for (int i = 0; i < index; ++i){
		aux = aux->getNext;
	}
	aux2 = aux->getNext();
	node<T> *nuevo = new node<T>(d);
	aux->setNext(nuevo);
	nuevo->setNext(aux2);
	return true;
}

template <typename T>
T LinkedList<T>::deleteFirst(){

	if (this->isEmpty())
		return NULL;

	T data = head->getData();
	node<T> *aux = head;
	head = head->getNext();
	delete aux;
	length--;
	return data;
}

template <typename T>
T LinkedList<T>::deleteLast(){
	if (this->isEmpty())
		return NULL;

	if (head->getNext == NULL)
		return deleteFirst();

	node<T> *aux = head;
	while (aux->getNext()->getNext() != NULL){ //aqui aux se parará en el penultimo nodo
		aux = aux->getNext;
	}
	T data = aux->getNext()->getData();//te da la info del ultimo elemento
	delete aux->getNext(); //borrando el ultimo elemento
	aux->setNext(NULL);
	length--;
	return data;
}

template <typename T>
int LinkedList<T>::deleteAll(){
	node<T> *aux = head;
	int count;
	while (head != NULL){
		aux = aux->getNext();
		delete head;
		head = aux;
		count++;
	}
	length = 0;
	return count;
}

template <typename T>
T LinkedList<T>::deleteNode(int index){

	if (index > length-1 || index < 0)
		return NULL;

	if (index == 0)
		return deleteFirst();
	else if (index == length-1)
		return deleteLast();

	node<T> *aux = head, *aux2, *nodeToDelete;
	for (int i = 0; i < index; ++i){
		aux = aux->getNext;
	}
	T data = aux->getNext()->getData();//te da la info del elemento a borrar
	nodeToDelete = aux->getNext();
	aux2 = aux->getNext()->getNext();
	aux->setNext(aux2);
	delete nodeToDelete;
	return data;
}

template <typename T>
T LinkedList<T>::setD(T d, int index){
	if (index > length-1 || index < 0)
		return NULL;

	node<T> *aux = head, *aux2;
	for (int i = 0; i <= index; ++i){
		aux = aux->getNext;
	}
	T data = aux->getData();
	aux->setData(d);
	return data;
}

template <typename T>
T LinkedList<T>::getD(int index){
	if (index > length-1 || index < 0)
		return NULL;

	node<T> *aux = head;
	for (int i = 0; i <= index; ++i){
		aux = aux->getNext;
	}
	T data = aux->getData();
	return data;
}

template <typename T>
bool LinkedList<T>::change(int index1, int index2){
	if (index1 >= length || index2 >= length)
		return false;
	if (index1 == index2)
		return true;

	int lowIndex = (index1 < index2)? index1 : index2;
	int topIndex = (index1 > index2)? index1 : index2;
	node<T> *aux1 = head;
	for (int i = 1; i <= lowIndex; ++i){
		aux1 = aux1->getNext();
	}
	node<T> *aux2 = aux1;
	for (int i = lowIndex; i < topIndex; ++i){
		aux2 = aux2->getNext();
	}
	T data = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(data);
	return true;
}

template <typename T>
void LinkedList<T>::print(){
	node<T> *aux = head;
	while (aux != NULL){
		cout << aux->getData() << " ";
		aux = aux->getNext();
	}
	cout << endl<< "FIN DE LA LISTA"<<endl;
}

/*
template <typename T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	//os << "[ ";
	node<T> *aux = list.head;
	while (aux != NULL){
		os << aux->getData() << " ";
		aux = aux->getNext();
	}
	//os << " ]" << endl; //<< "FIN DE LA LISTA" << endl;
	return os;
}*/

template <typename T>
void LinkedList<T>::reverse(){
	if (!length)
		return;
	else if (length == 1)
		return;
	else if (length == 2){
		change(0,1);
		return;
	}
	node<T> *prev, *next, *aux;
	prev = head;
	next = prev->getNext();
	aux = prev->getNext()->getNext();
	prev->setNext(NULL);
	while (aux != NULL){
		next->setNext(prev);
		prev = next;
		next = aux;
		aux = aux->getNext();
	}
	next->setNext(prev);
	head = next;
	delete aux;
}

template <typename T>
bool LinkedList<T>::operator==(LinkedList<T> &list){

	node<T> *aux = head, *aux2 = list.head;
	if (length != list.length)
		return false;
	else {
		while (aux != NULL && aux2 != NULL){
			if (aux->getData() != aux2->getData())
				return false;
			aux = aux->getNext();
			aux2 = aux2->getNext();
		}
	}
	return true;
}

