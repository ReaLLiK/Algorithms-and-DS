#include <iostream>
#include <vector>
using namespace std;
unsigned long long CnK(int n, int k, vector<vector<unsigned long long>> &buffer)
{
	if (buffer[k][n])
	{
		return buffer[k][n];
	}
	if ((n == k) || (!n) || (!k))
		return 1;
	buffer[k][n] = (CnK(n - 1, k, buffer) + CnK(n - 1, k - 1, buffer))%1000000007;
	return (CnK(n - 1, k, buffer) + CnK(n - 1, k - 1, buffer))%1000000007;
}

int  main()
{
	int n, k;
	cin >> n >> k;
	vector<unsigned long long> line;
	vector<vector<unsigned long long>> matrix;
		for (int j = 0; j <= n; ++j)
			line.push_back(0);
		for (int i = 0; i <= k; ++i)
			matrix.push_back(line);
	cout << CnK(n, k, matrix);
	return 0;
}
