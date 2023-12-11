#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream in;
ofstream out;

int main()
{
	in.open("huffman.in");
	out.open("huffman.out");
	int n;
	long long sum = 0, buffer, buffer2;
	priority_queue <long long,vector<long long>, greater<long long>> Bheap;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		in >> buffer;
		Bheap.push(buffer);
	}
	while (Bheap.size()!=1)
	{
		buffer = Bheap.top();
		Bheap.pop();
		buffer2 = Bheap.top();
		Bheap.pop();
		buffer += buffer2;
		sum += buffer;
		Bheap.push(buffer);
	}
	out << sum;
	return 0;
}
