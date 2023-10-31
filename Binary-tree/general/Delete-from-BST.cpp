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
    void LeftPreOrderTraversal(Node* Root)
    {
        if (Root != nullptr)
        {
            out << Root->Key << endl;;
            LeftPreOrderTraversal(Root->Left);
            LeftPreOrderTraversal(Root->Right);
        }
    }
    Node* RDelete(Node* Root, int key)
    {
        if (Root == nullptr)
            return nullptr;
        if (key < Root->Key)
        {
            Root->Left = RDelete(Root->Left, key);
            return Root;
        }
        else if (key > Root->Key)
        {
            Root->Right = RDelete(Root->Right, key);
            return Root;
        }
        if (Root->Left == nullptr)
            return Root->Right;
        else if (Root->Right == nullptr)
            return Root->Left;
        else
        {
            int min_key = Find_min(Root->Right)->Key;
            Root->Key = min_key;
            Root->Right = RDelete(Root->Right, min_key);
            return Root;
        }
     
    }
    Node* Find_min(Node* Root)
    {
        if (Root->Left != nullptr)
            return Find_min(Root->Left);
        else
            return Root;
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
    int n, target;
    in >> target;
    BinaryTree Tree;
    while (!in.eof())
    {
        in >> n;
        Tree.Insert(n);
    }
    Tree.Root=Tree.RDelete(Tree.Root, target);
    Tree.LeftPreOrderTraversal(Tree.Root);
    out.close();
    in.close();
    return 0;
}
