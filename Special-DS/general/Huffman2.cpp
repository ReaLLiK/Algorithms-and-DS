#include <fstream>
#include <vector>

using namespace std;

ifstream in;
ofstream out;

int main()
{
  in.open("huffman.in");
  out.open("huffman.out");
    long long n;
    in >> n;
    vector<long long> array1(n);
    for (int i = 0; i < n; ++i) 
    {
        in >> array1[i];
    }
    array1.push_back(LLONG_MAX);
    vector<unsigned long long> array2(n + 1, LLONG_MAX);
    int i = 0, j = 0;
    unsigned long long summator = 0;
    for (int k = 0; k < n - 1; ++k)
    {
        if ((array1[i + 1] <= array2[j]) && (array1[i] + array1[i + 1] <= array2[j] + array2[j + 1]) && (i < n - 1)) 
            {
                array2[k] = array1[i] + array1[i + 1];
                i += 2;
            }
        else
            if ((array2[j] + array2[j + 1] <= array1[i] + array1[i + 1]) && (array2[j + 1] <= array1[i]) && (j < n - 1)) 
            {
                array2[k] = array2[j] + array2[j + 1];
                j += 2;
            }
        else 
            if ((array2[j] <= array1[i + 1]) && (array1[i] <= array2[j + 1]) && (i < n) && (j < n)) 
            {
                array2[k] = array1[i] + array2[j];
                ++i;
                ++j;
            }
        summator += array2[k];
    }
    out << summator;
    out.close();
    in.close();
    return 0;
}
