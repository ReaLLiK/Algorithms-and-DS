#include <vector>
#include <fstream>
#include <queue>

using namespace std;

ifstream in;
ofstream out;

void Dijkstra(int start, vector<vector<pair<int, int>>> &matrix, vector<bool> &processed, vector<long long> &dist)
{
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) 
	{
		pair<long long, long long> top_pair = pq.top();
		long long dv = top_pair.first;
		long long v = top_pair.second;
		pq.pop();

		if (processed[v]) 
		{
			continue;
		}

		processed[v] = true;
		dist[v] = dv;

		for (pair<long long, long long> neighbor : matrix[v]) 
		{
			long long u = neighbor.first;
			long long cu = neighbor.second;

			if (!processed[u] && dv + cu < dist[u]) 
			{
				pq.push(make_pair(dv + cu, u));
			}
		}
	}
}

int main()
{
	in.open("input.txt");
	int NodesAmount, LinksAmount, first, second, price;
	in >> NodesAmount >> LinksAmount;
	vector<long long> dist(NodesAmount, LLONG_MAX);
	vector<bool> processed(NodesAmount, false);
	vector<vector<pair<int, int>>> matrix(NodesAmount);
	for (int i = 0; i < LinksAmount; ++i)
	{
		in >> first >> second >> price;
		matrix[first-1].emplace_back(second-1, price);
		matrix[second-1].emplace_back(first-1, price);
	}
	in.close();
	Dijkstra(0, matrix, processed, dist);
	out.open("output.txt");
	out << dist[NodesAmount - 1];
	out.close();
	return 0;
}
