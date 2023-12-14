#include <vector>
#include <fstream>
#include <queue>
#include<tuple>

using namespace std;

ifstream in;
ofstream out;

struct Edge
{
    int source;
    int target;
    int capacity;
    int cost;
    int flow;
};

vector<Edge> flow_edges;
vector<vector<int>> network;

void resize(int size)
{
    network.resize(size);
}

vector<int> edges(int v)
{
    return network[v];
}

int available(int e)
{
    Edge edge = flow_edges[e];
    return edge.capacity - edge.flow;
}

int flow(int e)
{
    Edge edge = flow_edges[e];
    return edge.flow;
}

int target(int e)
{
    Edge edge = flow_edges[e];
    return edge.target;
}

int source(int e)
{
    Edge edge = flow_edges[e];
    return edge.source;
}

int cost(int e)
{
    Edge edge = flow_edges[e];
    return edge.cost;
}

void push(int e, int flow)
{
    flow_edges[e].flow += flow;
    flow_edges[e ^ 1].flow -= flow;
}

void push_path(const std::vector<int>& path, int flow)
{
    for (int e : path)
    {
        push(e, flow);
    }
}

void build_network(int size, vector<vector<tuple<int, int, int>>>& matrix)
{
    for (int v = 0; v < size; ++v)
    {

        for (const auto& triple : matrix[v])
        {

            int cu = get<0>(triple);
            int pu = get<1>(triple);
            int u = get<2>(triple);

            network[v].push_back(flow_edges.size());
            flow_edges.push_back({ v, u, cu, pu, 0 });
            network[u].push_back(flow_edges.size());
            flow_edges.push_back({ u, v, 0, -pu, 0 });
        }
    }
}

vector<int> network_edges()
{
    vector<int> edges;

    for (int i = 0; i < flow_edges.size(); ++i)
    {
        edges.push_back(i);
    }

    return edges;
}

void find_path(int start, int size, vector<int>& dist, vector<int>& pred)
{
    dist[start] = 0;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int e : network_edges())
        {
            int v = source(e);
            int u = target(e);
            int c = cost(e);

            if (dist[v] == INT_MAX || available(e) == 0) {
                continue;
            }

            if (dist[u] == INT_MAX || dist[u] > dist[v] + c) {
                dist[u] = dist[v] + c;
                pred[u] = e;
            }
        }
    }
}


vector<int> restore_path(int t, vector<int>& pred)
{
    vector<int> path;

    while (pred[t] != -1)
    {
        int e = pred[t];
        path.push_back(e);
        t = source(e);
    }

    return path;
}

int path_capacity(const vector<int>& path)
{
    int cap = available(path[0]);

    for (int e : path)
    {
        cap = min(cap, available(e));
    }

    return cap;
}

int path_cost(const vector<int>& path)
{
    int totalCost = 0;

    for (int e : path)
    {
        totalCost += cost(e);
    }

    return totalCost;
}

bool relax(int v, int u, int c, int e, vector<int>& dist, vector<int>& pred)
{
    if (dist[u] > dist[v] + c) {
        dist[u] = dist[v] + c;
        pred[u] = e;
        return true;
    }
    return false;
}

pair<int, int> busacker_gowen(int s, int t, int size, vector<int>& pred, vector<int>& dist)
{
    int result_flow = 0;
    int result_cost = 0;

    while (true)
    {
        for (int v = 0; v < size; ++v)
        {
            pred[v] = -1;
            dist[v] = INT_MAX;
        }
        find_path(s, size, dist, pred);
        if (dist[t] == INT_MAX)
        {
            break;
        }
        auto path = restore_path(t, pred);
        int flow = path_capacity(path);
        int pcost = path_cost(path);
        push_path(path, flow);
        result_flow += flow;
        result_cost += flow * pcost;
    }
    return { result_flow, result_cost };
}

pair<int, int> min_cost_max_flow(int s, int t, int size, vector<vector<tuple<int, int, int>>>& matrix, vector<int>& dist, vector<int>& pred)
{
    if (s == t)
    {
        return { 0, 0 };
    }
    build_network(size, matrix);
    return busacker_gowen(s, t, size, pred, dist);
}


int main()
{
    in.open("input.txt");
    out.open("output.txt");
    int NodesAmount, LinksAmount, first, second, price, start, finish, Target;
    in >> NodesAmount >> LinksAmount;
    resize(2 * NodesAmount);
    vector<int> dist(2 * NodesAmount, INT_MAX);
    vector<bool> processed(2 * NodesAmount, false);
    vector<vector<tuple<int, int, int>>> matrix(2 * NodesAmount);
    vector<Edge> flow_edges;
    vector<int> pred(2 * NodesAmount);
    vector<bool> visited(NodesAmount, false);
    for (int i = 0; i < LinksAmount; ++i)
    {
        in >> first >> second >> price;
        if (!visited[first - 1])
            matrix[2 * first - 2].emplace_back(1, 0, 2 * first - 1);
        if (!visited[second - 1])
            matrix[2 * second - 2].emplace_back(1, 0, 2 * second - 1);
        matrix[2 * first - 1].emplace_back(1, price, 2 * second - 2);
        matrix[2 * second - 1].emplace_back(1, price, 2 * first - 2);
        visited[first - 1] = true;
        visited[second - 1] = true;
    }
    in >> start >> finish >> Target;
    for (int i = 0; i < Target; ++i)
    {
        matrix[2 * start - 2].emplace_back(1, 0, 2 * start - 1);
        matrix[2 * finish - 2].emplace_back(1, 0, 2 * finish - 1);
    }
    pair<int, int> answer;
    answer = min_cost_max_flow(2 * start - 2, 2 * finish - 2, 2 * NodesAmount, matrix, dist, pred);
    if (answer.first <= Target)
        out << "No\n" << answer.first;
    else
        out << "Yes\n" << answer.second;
    in.close();
    out.close();
    return 0;
}
