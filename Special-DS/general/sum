#include <vector>
#include <cmath>
#include <numeric>
#include <iostream>
#include <string>

using namespace std;

class Summator 
{
    vector<long long> a;
    int count;
    vector<long long> b;
public:
    Summator(const vector<long long>& a) : a(a)
    {
        count = (floor(sqrt(a.size())));

        for (int i = 0; i < a.size(); i += count)
        {
            long long bsum = 0;
            for (int j = i; j < min(i + count, (int)a.size()); ++j)
            {
                bsum += a[j];
            }
            b.push_back(bsum);
        }
    }

    void Add(int i, long long x)
    {
        a[i] += x;
        b[i / count] += x;
    }

    void FindSum(int left, int right)
    {
        int LeftBox = left / count;
        int RightBox = right / count;

        if (LeftBox == RightBox) 
        {
            long long sum = 0;
            for (int i = left; i < right; ++i) 
            {
                sum += a[i];
            }
            cout<< sum<<endl;
        }
        else
        {
            long long sum = 0;
            for (int i = left; i < (LeftBox + 1) * count; ++i)
                sum += a[i];
            for (int i = (LeftBox + 1); i<RightBox; ++i)
                sum += b[i];
            for (int i = RightBox*count; i < right; ++i)
                sum += a[i];
            cout<< sum<<endl;
        }
    }
};
int main()
{
    int number,buffer, left, right;
    string command;
    cin >> number;
    vector<long long> base(number);
    for (int i = 0; i < number; ++i)
        cin >> base[i];
    Summator summator(base);
    cin >> number;
    for (int i = 0; i < number; ++i)
    {
        cin >> command;
        cin >> left >> right;
        if (command == "Add")
            summator.Add(left, right);
        else
            summator.FindSum(left, right);
    }
    return 0;
}
