#include <fstream>
#include <vector>
using namespace std;
ifstream in;
ofstream out;

int main() 
{
    in.open("input.txt");
    out.open("output.txt");
    int n;
    in >> n;
    vector<int> Subs;
    int buffer;
    for (int i = 0; i < n; ++i) 
    {
        in >> buffer;
        Subs.push_back(buffer);
    }
    vector<int> a(n + 1, 1000000001);
    vector<int> b(n);
    a[0] = -1000000001;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(a.begin(), a.end(), Subs[i]) - a.begin();
        if (a[j - 1] < Subs[i] && Subs[i] < a[j])
        {
            a[j] = Subs[i];
            b[i] = j - 1;
        }
    }
    int lenght = 0;
    for (int i = 1; i <= n; ++i) 
    {
        if (a[i] != 1000000001) 
        {
            lenght = i;
        }
    }
    out << lenght << endl;
    out.close();
    in.close();
    return 0;
}
