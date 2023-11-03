#include <fstream>

using namespace std;

ifstream in;
ofstream out;

struct arrays
{
	int* parent;
	int* size;
};
class DSU
{
	arrays self;
	int amount;
	int counter;
public:
	DSU(int nCities)
	{
		amount = nCities + 1;
		counter = nCities;
		self.size = new int[nCities+1];
		self.parent = new int[nCities + 1];
		for (int i = 1; i < nCities + 1; ++i)
		{
			self.size[i] = 1;
			self.parent[i] = i;
		}
	}
	~DSU()
	{
		delete[] self.parent;
		delete[] self.size;
	}
	void UnionAndCount(int x, int y)
	{
		x = FindSet(x);
		y = FindSet(y);
		if (x != y)
		{
			counter--;
		}
			if (self.size[x] < self.size[y])
				swap(x, y);
				self.parent[y] = x;
				self.size[x] += self.size[y];
				out << counter << endl;
	}
private:
	int FindSet(int x)
	{
		if (x == self.parent[x])
			return x;
		self.parent[x] = FindSet(self.parent[x]);
			return self.parent[x];
	}
};

int main()
{
	in.open("input.txt");
	out.open("output.txt");
	int nCities1, nRequests;
	in >> nCities1>>nRequests;
	int x, y;
	DSU country(nCities1);
	for (int i = 0; i < nRequests; ++i)
	{
		in >> x >> y;
		country.UnionAndCount(x, y);
	}
	in.close();
	out.close();
	return 0;
}
