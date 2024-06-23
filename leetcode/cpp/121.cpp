// find the maximum difference between two increasing elements
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1, maxProfit = 0;
        while (r < prices.size())
        {
            int val = (prices[r] - prices[l]);
            if (val < 0)
            {
                l = r;
                r++;
            }
            else
            {
                maxProfit = max(maxProfit, val);
                r++;
            }
        }
        return maxProfit;
    }
    // Time-Complexity = O(n)
    // Space-Complexity = O(1)
};
int main()
{
    vector<int> v = {2, 1, 2, 1, 0, 1, 2};
    Solution *A = new Solution();
    cout << A->maxProfit(v);
}