#include <fstream>
using namespace std;

ifstream in;
ofstream out;


int matrix_chain_multiplication_order(int* numbers, int size)
{
    int** buffer = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        buffer[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        buffer[i][i] = 0;
    }
    for (int k = 2; k < size; ++k)
    {
        for (int i = 1; i < size - k + 1; ++i)
        {
            int j = i + k - 1;
            buffer[i][j] = 100000001;
            for (int l = i; l < j; l++)
            {
                buffer[i][j] = min(buffer[i][j], buffer[i][l] + buffer[l + 1][j] + (numbers[i - 1] * numbers[l] * numbers[j]));
            }
        }
    }
    return buffer[1][size - 1];
}

int main()
{
    in.open("input.txt");
    out.open("output.txt");
    int n;
    in >> n;
    int* numbers = new int[n + 1];
    for (int i = 0; i < n; ++i)
    {
        in >> numbers[i];
        in >> numbers[1+i];
    }
    out << matrix_chain_multiplication_order(numbers, n + 1) << endl;
    in.close();
    out.close();
    return 0;
}
