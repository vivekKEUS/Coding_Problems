
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
bool visited[MAX];
bool dfsUtilCycleCheck(int s, vector<int> adj[], int parent)
{
    if (visited[s])
        return false;
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] and u != parent)
            return true;
        dfsUtilCycleCheck(u, adj, s);
    }
}
bool dfs(vector<int> adj[], int N)
{
    bool result = false;
    for (auto i = 1; i <= N; i++)
    {
        result = dfsUtilCycleCheck(i, adj, 0);
        if (result)
            break;
    }
    return result;
}
int main()
{
    int N, M;
    cin >> N >> M; // N = vertices,M = edges
    vector<int> adj[N + 1];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            cout << "There is a motherfucking disconnected components.\n";
        }
    }
    dfs(adj, N);
}