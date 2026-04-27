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

bool validate(Node* root, long long minVal, long long maxVal)
{
    if (root == nullptr)
        return true;

    if (root->value <= minVal || root->value >= maxVal)
        return false;

    return validate(root->left, minVal, root->value) &&
           validate(root->right, root->value, maxVal);
}

bool validate(Node* root)
{
    return validate(root, -10000, 100000);
}