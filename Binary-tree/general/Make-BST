#include <iostream>
#include <fstream>
using namespace std;

ifstream in;
ofstream out;

class Node 
{
public:
    Node(int key) : Key(key)
    {};
    int Key;
    Node* Left = nullptr;
    Node* Right = nullptr;
};
class BinaryTree
{
public:
    BinaryTree() : Root(0)
    {}
    ~BinaryTree()
    {
        DestroyNode(Root);
    }
    Node* Root;
    void Insert(int n)
    {
        Node** current = &Root;
        while (*current)
        {
            Node& node = **current;
            if (n < node.Key)
                current = &node.Left;
            else if (n > node.Key)
                current = &node.Right;
            else
                return;
        }
        *current = new Node(n);
    }
    void LeftPreOrderTraversal(Node *Root)
    {
        if (Root != nullptr)
        {
            out << Root->Key << endl;;
            LeftPreOrderTraversal(Root->Left);
            LeftPreOrderTraversal(Root->Right);
        }
    }

private:
    static void DestroyNode(Node* node)
    {
        if (node) 
        {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }
};
int main()
{
    in.open("input.txt");
    out.open("output.txt");
    int n;
    BinaryTree Tree;
    while (!in.eof())
    {
        in >> n;
        Tree.Insert(n);
    }
    Tree.LeftPreOrderTraversal(Tree.Root);
    out.close();
    in.close();
    return 0;
}
