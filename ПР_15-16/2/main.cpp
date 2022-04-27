#include <bits/stdc++.h>
using namespace std;

// tree nod
struct Node
{
	int data;
	int key ,count;
	Node *left, *right;
};

// returns a new tree Node
Node* newNode(int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = data;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}

// A function to create binary search tree.
Node* Tree(Node* temp, int key )
{
    // If the tree is empty, return a new node
    if (temp == NULL)
        return newNode(key);
    if (key == temp->key)
    {
       (temp->count)++;
        return temp;
    }

    // Otherwise, recur down the tree
    if (key < temp->key)
        temp->left = Tree(temp->left, key);
    else
        temp->right = Tree(temp->right, key);

    //return the (unchanged) node pointer
    return temp;
}

//function to display all the element present in the binary search tree
void displayTree(struct Node* root)
{
    if (root != NULL)
    {
        displayTree(root->left);
        cout<<"Number "<<root->key<<" duplicated times: "<<root->count<<endl;
        displayTree(root->right);

    }
}

int main()
{
	int arr[20],size;
	Node *root = new Node;
	root = NULL;

	cout<<"Enter the size of array : ";
	cin>>size;

	cout<<"Enter the elements in array : ";
	for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
	// Construct the binary tree.
	for(int i = 0; i < size; i++)
	{
	    root = Tree(root, arr[i]);
	}

	displayTree(root);

	return 0;
}
