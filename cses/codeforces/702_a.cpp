
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int maxLength = 1, length = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
        {
            length++;
        }
        else
        {
            length = 1;
        }
        maxLength = max(maxLength, length);
    }
    cout << maxLength << endl;
    return 0;
}