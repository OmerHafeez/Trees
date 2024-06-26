#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int dat)
	{
		data = dat;
		left = nullptr;
		right = nullptr;
	}
};

class Tree 
{
public:
	Node* Root;

	Tree()
	{
		cout << "Hi" << endl;
		Root = nullptr;
	}



	Node* create_Node(int val)
	{
		Node* newNode = new Node(val);
		if (newNode == nullptr)
		{
			cout << "Space not allocated" << endl;
		}
		else
		{
			newNode->data = val;
			return newNode;
		}
	}

	Node* add_Node(Node* key, int val)
	{
		if (key == nullptr)
		{
			// If the current node is null, create a new node and return it as the new root.
			return create_Node(val);
			cout << "G";
		}

		if (val < key->data)
		{
			// Recursively insert the value into the left subtree.
			key->left = add_Node(key->left, val);
			cout << "K";
		}
		else if (val > key->data)
		{
			// Recursively insert the value into the right subtree.
			key->right = add_Node(key->right, val);
		}

		// Return the updated root of the subtree.
		return key;
	}


	void Infix(Node* key)
	{
		if (key == nullptr)
			return;
		Infix(key->left);
		cout << key->data<<"\t";
		Infix(key->right);
	}

	void Prefix(Node* key)
	{
		if (key == nullptr)
			return;
		cout << key->data<<"\t";
		Prefix(key->left);
		Prefix(key->right);
	}

	void Postfix(Node* key)
	{
		if (key == nullptr)
			return;
		Postfix(key->left);
		Postfix(key->right);
		cout << key->data << "\t";
	}

	void menu()
	{

		int choice = -1; // Initialize choice to a non-zero value

		while (choice != 0)
		{
			cout << "Binary Search Tree Menu:" << endl;
			cout << "1. Inset Node" << endl;
			cout << "2. Infix" << endl;
			cout << "3. Prefix" << endl;
			cout << "4. Postfix" << endl;
			//cout << "5. Delete Node at start" << endl;
			//cout << "6. Delete Node at End" << endl;
			//cout << "7. Delete Node at Random Position" << endl;
			//cout << "8. Display List" << endl;
			//cout << "9. Display reversed List" << endl;
			cout << "0. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			if (choice == 1)
			{
				int value;
				cout << "Enter the value you want to store" << endl;
				cin >> value;
				add_Node(Root, value);
			}
			else if (choice == 2)
				Infix(Root);
			else if (choice == 3)
				Prefix(Root);
			else if (choice == 4)
				Postfix(Root);
			//else if (choice == 5)
			//	delete_Node_start();
			//else if (choice == 6)
			//	delete_Node_end();
			////else if (choice == 7) 
			////  myList.delete_Node_Random();
			//else if (choice == 8)
			//	displayList();
			//else if (choice == 9)
			//	displayList_reverse();
			else if (choice == 0)
				cout << "Exiting..." << endl;
			else
				cout << "Invalid choice! Please try again." << endl;

		}
	}
};

int main()
{
	Tree* obj = new Tree;
	obj->menu();
}