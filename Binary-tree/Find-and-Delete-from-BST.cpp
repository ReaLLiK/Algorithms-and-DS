#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

ifstream in;
ofstream out;

class Node
{
public:
    Node(int key) : Key(key)
    {};
    int Key;
    int high;
    int Nsons;
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
    void LeftPostOrderTraversal(Node* Root)
    {
        if (Root != nullptr)
        {
            LeftPostOrderTraversal(Root->Left);
            LeftPostOrderTraversal(Root->Right);
            if ((Root->Right != nullptr) && (Root->Left != nullptr))
            {
                Root->high = max(Root->Left->high, Root->Right->high) + 1;
                Root->Nsons = Root->Left->Nsons + Root->Right->Nsons + 2;
            }
            else
            {
                if ((Root->Left == nullptr) && (Root->Right == nullptr))
                {
                    Root->high = 0;
                    Root->Nsons = 0;
                }
                else
                {
                    if (Root->Left == nullptr)
                    {
                        Root->high = Root->Right->high + 1;
                        Root->Nsons = Root->Right->Nsons + 1;
                    }
                    if (Root->Right == nullptr)
                    {
                        Root->high = Root->Left->high + 1;
                        Root->Nsons = Root->Left->Nsons + 1;
                    }
                }
            }
        }

    }
    void LeftPreOrderTraversal(Node* Root)
    {
        if (Root != nullptr)
        {
            out << Root->Key << endl;
            LeftPreOrderTraversal(Root->Left);
            LeftPreOrderTraversal(Root->Right);
        }
    }
    void LeftPreOrderTraversal1(Node* Root, vector<int>& array)
    {
        if (Root != nullptr)
        {
            if ((Root->Left != nullptr) && (Root->Right != nullptr))
                if ((Root->Right->high == Root->Left->high) && (Root->Left->Nsons != Root->Right->Nsons))
                    array.push_back(Root->Key);
            LeftPreOrderTraversal1(Root->Left, array);
            LeftPreOrderTraversal1(Root->Right, array);
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
    in.open("in.txt");
    out.open("out.txt");
    int n;
    BinaryTree Tree;
    if (in.peek() == EOF)
        return 0;
    while (!in.eof())
    {
        in >> n;
        Tree.Insert(n);
    }
    vector<int> array;
    Tree.LeftPostOrderTraversal(Tree.Root);
    Tree.LeftPreOrderTraversal1(Tree.Root, array);
    sort(array.begin(), array.end());
    if (array.size() % 2 != 0)
        Tree.RDelete(Tree.Root, array[array.size() / 2]);
    Tree.LeftPreOrderTraversal(Tree.Root);
    out.close();
    in.close();
    return 0;
}
