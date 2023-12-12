#include <fstream>
#include <vector>
using namespace std;

ifstream in;
ofstream out;


void DFS(int start,int size,vector<vector<int>> &matrix, vector<bool> &visited, vector<int> &order, int &next_index)
{
	visited[start] = true;
	order[start] = next_index++;
	for (int i = 0; i < size; ++i)
	{
		if ((matrix[start][i] == 1) && (!visited[i]))
			DFS(i, size, matrix, visited, order, next_index);
	}
}

int main()
{
	int size, buffer, next_index=0;
	in.open("input.txt");
	in >> size;
	vector<vector<int>> matrix(size);
	vector<bool> visited(size, false);
	vector<int> order(size, 0);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
		{
			in >> buffer;
			matrix[i].push_back(buffer);
		}
	in.close();
	DFS(0,size, matrix, visited, order, next_index);
	for (int i = 0; i < size; ++i)
	{
		if (visited[i] == false)
			DFS(i, size, matrix, visited, order, next_index);
	}
	out.open("output.txt");
	for (int i = 0; i < size; ++i)
		out << order[i]+1 << ' ';
	out.close();
	return 0;
}
