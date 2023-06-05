#include <iostream>
#include <stack>
#include <string>
using namespace std;

class node
{
public:
    node *right;
    node *left;
    node *root;
    char data;

    node(char data, node *left, node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    node(char data)
    {
        this->data = data;
    }

    node()
    {
        root = NULL;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    node *current = root;
    node *prev = NULL;

    while (current || !s.empty())
    {
        if (current)
        {
            s.push(current);
            current = current->left;
        }
        else
        {
            node *temp = s.top();

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

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

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

node *exptree(string postfix)
{
    if (postfix.length() == 0)
    {
        return NULL;
    }

    stack<node *> s;

    for (char c : postfix)
    {
        if (isOperator(c))
        {
            node *x = s.top();
            s.pop();

            node *y = s.top();
            s.pop();

            node *nod = new node(c, y, x);

            s.push(nod);
        }
        else
        {
            s.push(new node(c));
        }
    }

    return s.top();
}

int main()
{
       //string postfix = "ab+cde+**";
     string postfix;
    cout << "Enter the expression:";
    cin >> postfix;
    node *root = exptree(postfix);

    cout << "Postfix Expression: ";
    postorder(root);

    cout << "\nInfix Expression: ";
    inorder(root);
    cout << "\n";

    return 0;
}
