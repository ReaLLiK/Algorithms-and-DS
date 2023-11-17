#include <fstream>

using namespace std;

ifstream in;
ofstream out;

struct arrays
{
	int* parent;
	int* size;
};
struct strips 
{
	int first;
	int second;
	bool flag=0;
};
class DSU
{
public:
	int counter;
	DSU(int nCities)
	{
		counter = nCities;
		self.size = new int[nCities + 1];
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
	}
private:
	arrays self;
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
	int nCities1, nRequests, nDestroys;
	in >> nCities1 >> nRequests >> nDestroys;
	DSU country(nCities1);
	int x, y;
	strips* roads = new strips[nRequests+1];
	char* answer = new char[nDestroys+1];
	int* destroyed = new int[nDestroys];
	for (int i = 0; i <= nDestroys; ++i)
	{
		answer[i] = '1';
	};
	for (int i = 1; i <= nRequests; ++i)
	{
		in >> x >> y;
		roads[i].first = x;
		roads[i].second = y;
	}
	for (int i = 0; i < nDestroys; ++i)
	{
		in >> destroyed[i];
		roads[destroyed[i]].flag = 1;
	}
	in.close();
	for (int i = 1; i <= nRequests; ++i)
	{
		if(roads[i].flag==0)
 		country.UnionAndCount(roads[i].first, roads[i].second);
	}
	for (int i = 1; i <= nDestroys; ++i)
	{
		if (country.counter != 1)
			answer[nDestroys - i + 1] = '0';
		country.UnionAndCount(roads[destroyed[nDestroys - i]].first, roads[destroyed[nDestroys - i]].second);
	}
	out.open("output.txt");
	for(int i=1; i<=nDestroys; ++i)
		out << answer[i];
	out.close();
	return 0;
}
