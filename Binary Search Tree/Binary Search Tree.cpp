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
			ROOT = newNode; // Tandai new node sebagai ROOT 
			return; // Exit
		}

		if (element < parent->info) //Jika data field new Node lebih kecil dari parent
		{
			parent->leftchild = newNode; // Membuat left child dari parent point ke new Node
		}
		else if (element > parent->info) //Jika data field new Node lebih besar dari parent
		{
			parent->rightchild = newNode; // Membuat right child dari parent  ke new Node
		}
	}


	void search(string element, Node*& parent, Node*& currentNode)
	{
		//Fungsi ini mencari Node saat ini dari Node yang ditenukan serta Node saat ini dari parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		//Melakukan postorder traversal tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree obj;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inordeer traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : " << endl;

		char ch;
		cin >> ch;
		cout << endl;
	}
}