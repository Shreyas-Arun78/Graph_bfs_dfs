/*
    Author : Shreyas Arun
    Date : 23-12-2025
    Purpose : Studying
*/
// Actually i love when my code goes too long (not intentionally ) , and i nver bother to push my project on GitHub but i want to push cuz i don't wanna delete it . So yeah enjoy this .. my future Shreyas Arun!

#include <bits/stdc++.h>
using namespace std;

void dfs(int nodes, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &ans) // replace with "size" if you wanna know the size of connected components
{
    visited[nodes] = 1;
    // size++;
    ans.push_back(nodes);
    for (int j = 0; j < adj_list[nodes].size(); j++)
    {
        if (!visited[adj_list[nodes][j]])
        {
            dfs(adj_list[nodes][j], adj_list, visited, size);
        }
    }
}

void bfs(int n, vector<vector<int>> &adj_list, vector<int> &ans)
{
    queue<int> q;
    q.push(n);
    vector<bool> visited(adj_list.size(), 0);
    visited[n] = 1;
    while (!q.empty())
    {
        int nodes = q.front();
        q.pop();
        ans.push_back(nodes);
        for (int j = 0; j < adj_list[nodes].size(); j++)
        {
            if (!visited[adj_list[nodes][j]])
            {
                visited[adj_list[nodes][j]] = 1;
                q.push(adj_list[nodes][j]);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    cout << "Printing Graph : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            if (j + 1 == adj_list[i].size())
            {
                cout << adj_list[i][j];
            }
            else
            {
                cout << adj_list[i][j] << " , ";
            }
        }
        cout << '\n';
    }
    cout << '\n';

    vector<bool> visited(n, 0);
    vector<int> ans;

    cout << "Traversing Graph via BFS : \n";

    bfs(0, adj_list, ans);
    for (auto &i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n'
         << '\n';
    ans.clear();
    cout << "Travesing Graph via DFS : \n";
    dfs(0, adj_list, visited, ans);
    for (auto &i : ans)
    {
        cout << i << ' ';
    }

    cout << '\n'
         << '\n';
    // visited.assign(n,false);
    // int comp_conn = 0;
    // vector<int> comp;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         int size = 0;
    //         dfs(i, adj_list, visited, size);
    //         comp_conn++;
    //         comp.push_back(size);
    //     }
    // }
    // cout << "Connected Commponent : " << comp_conn<<'\n';
    // cout << "Size of each component : ";
    // for (auto i : comp)
    // {
    //     cout << i << ' ';
    // }
    cout << '\n'
         << '\n';
    cout << "That's all !";
    cout << '\n'
         << '\n';
}

int main()
{
    solve();
}