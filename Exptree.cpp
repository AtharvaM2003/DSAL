#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    Node *current = root;
    Node *prev = nullptr;

    while (current || !s.empty())
    {
        if (current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            Node *temp = s.top();

            // If the right child exists and traversing
            // from the left child, then move right
            if (temp->right && temp->right != prev)
            {
                current = temp->right;
            }
            else
            {
                cout << temp->data << " ";
                s.pop();
                prev = temp;
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    if (isOperator(root->data))
    {
        cout << "(";
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);

    if (isOperator(root->data))
    {
        cout << ")";
    }
}

Node *exptree(string postfix)
{
    if (postfix.length() == 0)
        return nullptr;

    stack<Node *> s;

    for (char c : postfix)
    {
        if (isOperator(c))
        {
            Node *x = s.top();
            s.pop();

            Node *y = s.top();
            s.pop();

            Node *nod = new Node(c, y, x);

            s.push(nod);
        }
        else
        {
            s.push(new Node(c));
        }
    }

    return s.top();
}

int main()
{
    string postfix;
    cout << "Enter the expression: ";
    cin >> postfix;
    Node *root = exptree(postfix);

    cout << "Postfix Expression: ";
    postorder(root);

    cout << "\nInfix Expression: ";
    inorder(root);
    cout << "\n";

    return 0;
}
