#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long long unsigned llu;
inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    fast_io();
    lli T;
    cin >> T;
    if(T==0)cout<<1<<endl;
    else cout<< 3*T*(T+1) +1 <<endl;
}