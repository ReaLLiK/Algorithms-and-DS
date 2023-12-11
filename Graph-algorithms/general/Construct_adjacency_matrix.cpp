#include <fstream>;
using namespace std;
ifstream in;
ofstream out;
int main()
{
	in.open("input.txt");
	int n;
	in >> n;
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n] {0};
	int amount;
	in >> amount;
	pair<int, int> nodes;
	for (int i = 0; i < amount; ++i)
	{
		in >> nodes.first >> nodes.second;
		matrix[nodes.first-1][nodes.second-1] = 1;
		matrix[nodes.second-1][nodes.first-1] = 1;
	}
	in.close();
	out.open("output.txt");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			out << matrix[i][j] << ' ';
		out << endl;
	}
	out.close();
	return 0;
}
