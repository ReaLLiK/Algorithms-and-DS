#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindWay(int* buffer, int n, vector<int>& way)
{
	way.push_back(n);
	if (n == 3)
		way.push_back(1);
	if (n < 4)
		return 0;
	if (buffer[n - 2] > buffer[n - 3])
		FindWay(buffer, n - 2, way);
	else
		FindWay(buffer, n - 3, way);
}

int Kuvshinki(int* bees, int* buffer, int n)
{
	buffer[1] = bees[1];
	buffer[2] = -1;
	buffer[3] = bees[3] + bees[1];
	for (int i = 4; i <= n; ++i)
		buffer[i] = max(buffer[i - 2], buffer[i - 3]) + bees[i];
	return buffer[n];
};

	int komar[100001];
	int pepega[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; ++i)
		cin >> komar[i];
	for (int i = 0; i < 100001; ++i)
		pepega[i] = -2;
	vector<int> zhaba;
	cout << Kuvshinki(komar, pepega, n) << endl;
	FindWay(pepega, n, zhaba);
	if (n != 2)
		for (int i = zhaba.size() - 1; i > -1; --i)
			cout << zhaba[i] << ' ';
	return 0;
}
