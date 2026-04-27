#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>

using namespace std;

// COMENTARII ADAUGATE DE GPT COD SCRIS NATURAL DE MANA

const int N = 1e5;

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

class BinarySearchTree {
private:
    Node* root;

    // ===== INSERT (internal recursive) =====
    Node* insert(Node* node, int x)
    {
        if (node == nullptr)
            return new Node(x);

        if (x > node->value)
            node->right = insert(node->right, x);
        else
            node->left = insert(node->left, x);

        if (node->left)
            node->left->parent = node;
        if (node->right)
            node->right->parent = node;

        return node;
    }

    // ===== SUCCESSOR =====
    Node* succ(Node* node)
    {
        if (!node || !node->right) return nullptr;

        node = node->right;
        while (node->left)
            node = node->left;

        return node;
    }

    // ===== PREDECESSOR =====
    Node* precc(Node* node)
    {
        if (!node || !node->left) return nullptr;

        node = node->left;
        while (node->right)
            node = node->right;

        return node;
    }

    // ===== DELETE NODE =====
    void erase_after_find(Node*& node)
    {
        if (!node) return;

        // 0 children
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }

        // 1 right child
        else if (!node->left)
        {
            Node* child = node->right;
            if (node->parent)
            {
                if (node->parent->left == node)
                    node->parent->left = child;
                else
                    node->parent->right = child;
            }

            child->parent = node->parent;
            delete node;
            node = child;
        }

        // 1 left child
        else if (!node->right)
        {
            Node* child = node->left;
            if (node->parent)
            {
                if (node->parent->left == node)
                    node->parent->left = child;
                else
                    node->parent->right = child;
            }

            child->parent = node->parent;
            delete node;
            node = child;
        }

        // 2 children
        else
        {
            Node* replacement = succ(node);

            node->value = replacement->value;

            erase_after_find(replacement);
        }
    }

    // ===== FIND (internal) =====
    Node* find(Node* node, int x)
    {
        if (!node || node->value == x)
            return node;

        if (x < node->value)
            return find(node->left, x);

        return find(node->right, x);
    }

    // ===== TRAVERSAL =====
    void tranv(Node* node, int lvl)
    {
        if (!node) return;

        cout << "Nivelul " << lvl << " " << node->value;

        if (node->left && node->right)
            cout << " COPIII: " << node->left->value << " " << node->right->value;
        else if (node->left)
            cout << " LEFT: " << node->left->value;
        else if (node->right)
            cout << " RIGHT: " << node->right->value;
        else
            cout << " FRUNZA";

        cout << '\n';

        tranv(node->left, lvl + 1);
        tranv(node->right, lvl + 1);
    }

public:
    // ===== CONSTRUCTOR =====
    BinarySearchTree()
    {
        root = nullptr;
    }

    // ===== PUBLIC INSERT =====
    void insert(int x)
    {
        root = insert(root, x);
    }

    // ===== PUBLIC DELETE =====
    void erase(int x)
    {
        Node* node = find(root, x);
        if (node)
            erase_after_find(node);
    }

    // ===== PUBLIC TRAVERSAL =====
    void print()
    {
        tranv(root, 0);
    }

    // ===== BUILD FROM VECTOR =====
    void construct(vector<int> v)
    {
        for (int x : v)
            insert(x);
    }

    bool exists(int x)
    {
        if(find(root,x))
            return 1;
        return 0;
    }
};

int main()
{
	vector<int> v = { 1,3,6,4,7,8,10,14,13 };
	BinarySearchTree myTree;
    myTree.construct(v);
    myTree.erase(6);
    myTree.print();
}
