#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor untuk node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // Inisialisasi ROOT ke NULL
	}

	void insert(string element) // Memasukkan Node kedalam Binary Search Tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Menyiapkan memory untuk new Node
		newNode->info = element; // Menetapkan nilai ke data field new Node
		newNode->leftchild = NULL; // Buat left child dari new Node ke NULL
		newNode->rightchild = NULL; // Buat right child dari new Node ke NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // Menemukan node yang akan menjadi parent dari Node yang disisipkan

		if (parent == NULL) //Jika parentnya adalah NULL (Tree is empty)
		{

		}
	}
};