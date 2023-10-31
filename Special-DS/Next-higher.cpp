#include<vector>
#include<fstream>
#include<stack>
using namespace std;

ifstream in;
ofstream out;

int main()
{
    in.open("in.txt");
    out.open("out.txt");
    vector<int> nums;
    int buffer;
    while (!in.eof())
    {
        in >> buffer;
        nums.push_back(buffer);
    }
    int n = nums.size() - 1;
    vector<int>ans(nums.size());
    stack<int> st;
        for (int i = n; i >= 0; --i)
        {
            int curr = nums[i];
            while (!st.empty() && nums[st.top()] <= curr)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = 0;
            }
            else 
            {
                ans[i] = nums[st.top()];
            }
            st.push(i);
        };
        for(int i=0; i<n; ++i)
        {
            if (i != n - 1)
                out << ans[i] << ' ';
            else
                out << ans[i];
        }
    out.close();
    in.close();
    return 0;
};
