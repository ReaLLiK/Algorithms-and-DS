#include <fstream>
#include <string>
using namespace std;

ifstream in;
ofstream out;

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	char* mass = new char[7001];
	int n, i = 0;
	char temp;
	while (in >> temp)
	{
		mass[i] = temp;
		i++;
	}
	n = i;
	int** matrix = new int* [n + 1];
	for (int i = 0; i < n + 1; ++i)
		matrix[i] = new int[n + 1];
	for (int j = 0; j < n + 1; ++j)
	{
		matrix[j][0] = 0;
		matrix[0][j] = 0;
	}
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = i; j < n + 1; ++j)
		{
			if (mass[i - 1] == mass[n - j])
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else
				matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
		}
		for (int j = i + 1; j < n + 1; ++j)
		{
			if (mass[j - 1] == mass[n - i])
				matrix[j][i] = matrix[j - 1][i - 1] + 1;
			else
				matrix[j][i] = max(matrix[j][i - 1], matrix[j - 1][i]);
		}
	}
	string s;
	int h = 0, j = n;
	i = n;
	while ((i > 0) && (j > 0) && (h < (matrix[n][n] + 1) / 2))
	{
		if ((matrix[i][j] != matrix[i][j - 1]) && (matrix[i][j] != matrix[i - 1][j]))
		{
			s += mass[i - 1];
			h+=1;
			if (j > 1) 
			{
				j-=1;
				while ((matrix[i][j] == matrix[i - 1][j]) && (i > 1))
					i-=1;
				while ((matrix[i][j] == matrix[i][j - 1]) && (j > 1))
					j-=1;
			}
			else
				break;
		}
		else
		{
			if (i > 1)
			{
				while ((matrix[i][j] == matrix[i - 1][j]) && (i > 1))
					i-=1;
				while ((matrix[i][j] == matrix[i][j - 1]) && (j > 1))
					j-=1;
			}
			else j-=1;
		}
	}
	for (int i = h; i < matrix[n][n]; ++i)
		s += s.at(matrix[n][n] - i - 1);
	out << matrix[n][n] << endl << s;
	out.close();
	in.close();
	return 0;
}
