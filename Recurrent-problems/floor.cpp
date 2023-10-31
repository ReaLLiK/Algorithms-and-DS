#include <iostream>
#include <fstream>
using namespace std;
ifstream in;
ofstream out;
unsigned long long dp[3][10000000]{ 0 };
int main()
{
	in.open("in.txt");
	out.open("out.txt");
	int num;
	in >> num;
	dp[0][0] = 1;
	for (int i = 1; i <= num; ++i)
	{
		if (i % 2 == 1)
			dp[2][i] = (dp[0][i - 1]%1000000007) + ((2 * dp[1][i - 1]) % 1000000007) % 1000000007;
		else
		{
			dp[1][i] = dp[2][i - 1];
			dp[0][i] = ((3 * dp[0][i - 2]) % 1000000007) + ((2 * dp[1][i]) % 1000000007) % 1000000007;
		}
	}
	out << dp[0][num];
	in.close();
	out.close();
	return 0;
}
