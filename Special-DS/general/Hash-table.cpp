#include <fstream>

using namespace std;

ifstream in;
ofstream out;

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	int m, c, n, key;
	in >> m>>c>>n;
	int* hashTable = new int[m];
	for (int i = 0; i < m; ++i)
	{
		hashTable[i] = -1;
	}
	for (int i = 0; i < n; ++i)
	{
		int try_number = 0, position;
		in >> key;
		position = ((key % m) + c * try_number++) % m;
		if (hashTable[position] == -1)
			hashTable[position] = key;
		else
		{
			if (hashTable[position] == key)
			{
				continue;
			}
			else
			{
				do
				{
					position = ((key % m) + c * try_number++) % m;
				} while ((hashTable[position] != -1) && (hashTable[position] != key));
				if ((position < m) && (hashTable[position] == -1))
				{
					hashTable[position] = key;
				}
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		out << hashTable[i] <<' ';
	}
	out << endl;
	in.close();
	out.close();
	return 0;
}
