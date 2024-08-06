#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef long long unsigned llu;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::vector<vector<long long>> vvll;
const int MOD = 1e9 + 7;

// Fast I/O setup
inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout.tie(NULL);
}

// Template function to input elements into a vector
template <typename T>
void inputVector(vector<T> &v, int n)
{
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
}

// Template function to output elements of a vector
template <typename T>
void outputVector(const vector<T> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    fast_io();
    ll T;
    std::cin >> T;
    while (T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int count = 0;
        if (a > c and b > d)
        {
            count += 2;
        }
        if (b > c and a > d)
        {
            count += 2;
        }
        if (a > d and b == c)
        {
            count += 2;
        }
        if (b > d and a == c)
        {
            count += 2;
        }
        if (a > c and b == d)
        {
            count += 2;
        }
        if (b > c and a == d)
        {
            count += 2;
        }

        cout << count << endl;
    }

    return 0;
}