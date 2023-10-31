#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int buffer[1005][1005], buffer1[1005], buffer2[1005];
int main()
{
    int size;
    cin >> size;
    
    for (int i = 0; i < size; ++i)
        cin >> buffer1[i];
    for (int i = 0; i < size; ++i)
        cin >> buffer2[i];
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            if (buffer1[i - 1] == buffer2[j - 1])
                buffer[i][j] = buffer[i - 1][j - 1] + 1;
            else
                buffer[i][j] = max(buffer[i - 1][j], buffer[i][j - 1]);
        }
    }
    vector <int> first;
    vector<int> second;
    int i = size;
    int j = size;
    while ((i > 0) && (j > 0))
    {
        if (buffer1[i - 1] == buffer2[j - 1])
        {
            first.push_back(i - 1);
            second.push_back(j - 1);
            i-=1;
            j-=1;
        }
        else
        {
            if (buffer[i - 1][j] > buffer[i][j - 1])
                i-=1;
            else
                j-=1;
        }
    }
    cout << buffer[size][size] << endl;
    for (int i = first.size() - 1; i >= 0; --i)
        cout << first[i] << ' ';
    cout << endl;
    for (int i = second.size() - 1; i >= 0; --i)
        cout << second[i] << ' ';
    return 0;
}
