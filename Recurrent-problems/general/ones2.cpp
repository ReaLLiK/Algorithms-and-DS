#include <iostream>
using namespace std;

unsigned long long ModularFactorial(unsigned long long n, unsigned long long k, unsigned long long modular)
{
	for (int i = n-1; i >  k; --i)
		n = (n * i) % modular;
	return n;
}
unsigned long long ModularPower(unsigned long long base, unsigned long long power, unsigned long long mod)
{
	unsigned long long buffer = 1;
	while (power > 0)
	{
		if (power % 2 == 1)
		{
			buffer = (buffer * base) % mod;
		}
		base = (base * base) % mod;
		power >>= 1;
	}
	return buffer;
}
int main()
{
	unsigned long long n, k, znam, chisl;
	cin >> n >> k;
	znam = ModularFactorial(n - k, 1, 1000000007);
	chisl = ModularFactorial(n, k, 1000000007);
	znam = ModularPower(znam, 1000000005, 1000000007);
	cout << ((chisl % 1000000007) * (znam % 1000000007)) % 1000000007;
	return 0;
}
