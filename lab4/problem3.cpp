#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int x)
	{
		value = x;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

vector<Node*> v;

bool validate(Node* root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return true; // shouldnt be the case

    if (root->value <= minVal || root->value >= maxVal){
        v.push_back(root);
        return false;
    }

    return validate(root->left, minVal, root->value) &&
           validate(root->right, root->value, maxVal);
}

bool recover(Node* root)
{
    validate(root, -10000, 100000);
    Node* aux = v[0];
    v[0] = v[1];
    v[1] = aux;
}