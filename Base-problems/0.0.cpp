
#include <iostream>
#include <fstream>
#include <set>
#include <numeric>
using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    long long sum=0;
    in.open("input.txt");
    out.open("output.txt");
    long a;
    set <int> tree;
    while (!in.eof())
    {
        in >> a;
        tree.insert(a);
    }
    for (set<int>::iterator iterator = tree.begin(); iterator != tree.end(); ++iterator) 
    {
        sum += *iterator;
    }
    out<<sum;
    in.close();
    out.close();
    return 0;
}
