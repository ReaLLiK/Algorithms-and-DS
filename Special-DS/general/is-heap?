#include <fstream>
using namespace std;
ifstream in;
ofstream out;
int main()
{
	in.open("input.txt");
	out.open("output.txt");
	int n;
	in >> n;
	int* heap = new int[n];
	for (int i = 0; i < n; ++i)
		in >> heap[i];
	for (int i = 0; i < n; ++i)
	{
		if ((2 * i + 1 < n) && (heap[2 * i + 1] < heap[i]))
		{
			out << "No";
			return 0;
		}
		if ((2 * i + 2 < n) && (heap[2 * i + 2] < heap[i]))
		{
			out << "No";
			return 0;
		}
	}
	out << "Yes";
	in.close();
	out.close();
	return 0;
}
