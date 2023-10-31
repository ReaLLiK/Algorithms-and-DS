#include <fstream>
#include <iostream>
using namespace std;

ifstream in;
ofstream out;

struct Node 
{
	int lvl;
	int key;
	long long lowerB;
	long long upperB;
	char side;
};
int main()
{
	int size;
	in.open("bst.in");
	out.open("bst.out");
	in >> size;
	Node *array = new Node[size+1];
	in >> array[1].key;
	array[1].lowerB = LLONG_MIN;
	array[1].upperB = LLONG_MAX;
	array[1].lvl = 1;
	int dadlvl;
	for (int i = 2; i <=size; ++i)
	{
		array[i].lvl = i;
		in >> array[i].key;
		in >> dadlvl;
		in >> array[i].side;
		if (array[i].side=='R')
		{
			array[i].lowerB = array[dadlvl].key;
			array[i].upperB = array[dadlvl].upperB;
		}
		else
		{
			array[i].lowerB = array[dadlvl].lowerB;
			array[i].upperB = array[dadlvl].key;
		}
	}
	for (int i = 1; i <= size; ++i)
	{
		if ((array[i].key < array[i].lowerB) || (array[i].key >= array[i].upperB))
		{
			size = 0;
			break;
		}
	}
	if (size == 0)
		out << "NO";
	else
		out << "YES";
	in.close();
	out.close();
	return 0;
}
