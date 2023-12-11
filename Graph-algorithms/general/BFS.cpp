#include <vector> 
#include <queue> 
#include <fstream> 
#include <iostream> 
using namespace std;
ifstream in;
ofstream out;

void BFS(int start, vector<bool>& is_visited, vector<int>& order, vector<vector<int>>& graph, int &next_index, queue<int>& Q)
{
    int buffer;
    order[start] = next_index++;
    is_visited[start] = true;
    Q.push(start);
    while (!Q.empty())
    {
        buffer = Q.front();
        Q.pop();
        for (int i = 0; i < graph[buffer].size(); ++i)
        {
            if (!is_visited[graph[buffer][i]])
            {
                is_visited[graph[buffer][i]] = true;
                order[graph[buffer][i]] = next_index++;
                Q.push(graph[buffer][i]);
            }
        }

    }
    for (int i = 0; i < order.size(); ++i)
    {
        if (is_visited[i] == false)
        {
            BFS(i, is_visited, order, graph, next_index, Q);
        }
    }
}

int main()
{
    in.open("input.txt");
    out.open("output.txt");
    int size, buffer, index = 0, start = 0;
    in >> size;
    vector<bool> is_visited(size, false);
    vector<int> order(size,0);
    queue<int> Q;
    vector<vector<int>> graph(size);
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            in >> buffer;
            if (buffer == 1)
                graph[i].push_back(j);
        }
    }
    BFS(start, is_visited, order, graph, index, Q);
    for (int i = 0; i < order.size(); ++i)
        out << order[i]+1 << ' ';
    in.close();
    out.close();
    return 0;
}
