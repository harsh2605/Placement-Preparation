// Want to create a graph and using the nodes and edges as values than
// Two methods are there :1.Matrix method
//                        2.Adjacency list method
// Matrix method of storing values

// Space complexity :O(N*N)
int main()
{
    vector<vector<int>> matrix;
    int n, m; // Where n defines the number of nodes in the graph;
    for (int i = 0; i < n; i++)
    {
        int u, v; // This are the nodes which are connected to each other
        cin >> u >> v;
        for (int j = 0; j < n; j++)
        {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
}

// for adjacency list
// Space complexity:O(2*E) where E is the number of edges
// If you want to make the nodes of the graph with the weighted edges in it you make the vector as vector<pair<int,int>>;
int main()
{
    vector<int> vt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
}

// BFS traversal in graph
// Time complexity : O(V)+O(2*E)
// Space Complexity : O(V)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    vis[0] = 1;
    vector<int> ans;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        for (auto itr : adj[ele])
        {
            if (!vis[itr])
            {
                vis[itr] = 1;
                q.push(itr);
            }
        }
    }
    return ans;
}

// Depth First Search(DFS)
//Time complexity:O(V)+O(2*E) where V is the number of node in the graph and E is the number of edges in the whole graph
//Space complexity :O(V)
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto itr : adj[node])
    {
        if (!vis[itr])
        {
            vis[itr] = 1;
            dfs(itr, vis, adj, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<int> vis(V, 0);
    dfs(0, vis, adj, ans);
    return ans;
}