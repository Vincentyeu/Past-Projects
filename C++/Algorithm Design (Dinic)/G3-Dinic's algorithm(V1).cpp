//Group 3
//Yeu Nian Yong 1211200470
//Liow Fong Zhi 1211200875
//Lo Jia Kai 1211200667
// C++ implementation of Dinic's Algorithm

#include <bits/stdc++.h>

using namespace std;
 
// A structure to represent a edge between
// two vertex
struct Edge {
    int v; // Vertex v (or "to" vertex)
           // of a directed edge u-v. "From"
           // vertex u can be obtained using
           // index in adjacent array.
 
    int flow; // flow of data in edge
 
    int C; // capacity
 
    int rev; // To store index of reverse
             // edge in adjacency list so that
             // we can quickly find it.
};
 
// Residual Graph
class Graph {
    int V; // number of vertex
    int* level; // stores level of a node
    vector<Edge>* adj;
 
public:
    Graph(int V)
    {
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }
 
    // add edge to the graph
    void addEdge(int u, int v, int C)
    {
        // Forward edge : 0 flow and C capacity
        Edge a{ v, 0, C, (int)adj[v].size() };
 
        // Back edge : 0 flow and 0 capacity
        Edge b{ u, 0, 0, (int)adj[u].size() };
 
        adj[u].push_back(a);
        adj[v].push_back(b); // reverse edge
    }
 
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxflow(int s, int t);
};
 
// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool Graph::BFS(int s, int t)
{
    for (int i = 0; i < V; i++)
        level[i] = -1;
 
    level[s] = 0; // Level of source vertex
 
    // Create a queue, enqueue source vertex
    // and mark source vertex as visited here
    // level[] array works as visited array also.
    list<int> q;
    q.push_back(s);
 
    vector<Edge>::iterator i;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            Edge& e = *i;
            if (level[e.v] < 0 && e.flow < e.C) {
                // Level of current vertex is,
                // level of parent + 1
                level[e.v] = level[u] + 1;
 
                q.push_back(e.v);
            }
        }
    }
 
    // IF we can not reach to the sink we
    // return false else true
    return level[t] < 0 ? false : true;
}
 
// A DFS based function to send flow after BFS has
// figured out that there is a possible flow and
// constructed levels. This function called multiple
// times for a single call of BFS.
// flow : Current flow send by parent function call
// start[] : To keep track of next edge to be explored.
//           start[i] stores  count of edges explored
//           from i.
//  u : Current vertex
//  t : Sink
int Graph::sendFlow(int u, int flow, int t, int start[])
{
    // Sink reached
    if (u == t)
        return flow;
 
    // Traverse all adjacent edges one -by - one.
    for (; start[u] < adj[u].size(); start[u]++) {
        // Pick next edge from adjacency list of u
        Edge& e = adj[u][start[u]];
 
        if (level[e.v] == level[u] + 1 && e.flow < e.C) {
            // find minimum flow from u to t
            int curr_flow = min(flow, e.C - e.flow);
 
            int temp_flow
                = sendFlow(e.v, curr_flow, t, start);
 
            // flow is greater than zero
            if (temp_flow > 0) {
                // add flow  to current edge
                e.flow += temp_flow;
 
                // subtract flow from reverse edge
                // of current edge
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
 
    return 0;
}
 
// Returns maximum flow in graph
int Graph::DinicMaxflow(int s, int t)
{
    // Corner case
    if (s == t)
        return -1;
 
    int total = 0; // Initialize result
 
    // Augment the flow while there is path
    // from source to sink
    while (BFS(s, t) == true) {
        // store how many edges are visited
        // from V { 0 to V }
        int* start = new int[V + 1]{ 0 };
 
        // while flow is not zero in graph from S to D
        while (int flow = sendFlow(s, INT_MAX, t, start))
 
            // Add path flow to overall flow
            total += flow;
    }
 
    // return maximum flow
    return total;
}
 
// Driver Code
int main()
{
    /*
    Graph g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);
    */
 
    /*
    Graph g(8);
    g.addEdge(0, 1, 16 );
    g.addEdge(0, 2, 13 ) ;
    g.addEdge(1, 3, 12);
    g.addEdge(2, 4, 14 );
    g.addEdge(3, 4, 4 );
    g.addEdge(4, 1, 10);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 6, 30);
    g.addEdge(6, 5, 7 );
    g.addEdge(5, 7, 18);
    g.addEdge(6, 7, 5);
    */
 
    /*
    Graph g(10);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 4, 14 );
    g.addEdge(3, 4, 22 );
    g.addEdge(4, 1, 10 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 6, 30 );
    g.addEdge(5, 6, 8 );
    g.addEdge(5, 7, 18 ); 
    g.addEdge(6, 8, 9 );
    g.addEdge(6, 7, 5 );
    g.addEdge(8, 7, 6 );
    g.addEdge(7, 9, 10 );
    g.addEdge(8, 9, 15 );
    g.addEdge(4, 5, 11);
    */
/*
    Graph g(12);
    g.addEdge(0, 1, 50);
    g.addEdge(0, 2, 40);
    g.addEdge(1, 3, 16);
    g.addEdge(2, 4, 14 );
    g.addEdge(3, 4, 22);
    g.addEdge(4, 1, 10 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 6, 30 );
    g.addEdge(5, 6, 34 );
    g.addEdge(5, 7, 18 ); 
    g.addEdge(6, 8, 10 );
    g.addEdge(8, 7, 15 );
    g.addEdge(7, 9, 10 );
    g.addEdge(9, 8, 11 );
    g.addEdge(8, 10, 15 );
    g.addEdge(9, 11, 12);
    g.addEdge(10, 11, 19 );
    g.addEdge(6, 7, 27);
    */
    
    Graph g(14);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 3, 48);
    g.addEdge(2, 4, 14 );
    g.addEdge(3, 4, 4 );
    g.addEdge(4, 1, 10 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 6, 30 );
    g.addEdge(5, 6, 7 );
    g.addEdge(5, 7, 18 ); 
    g.addEdge(6, 8, 9 );
    g.addEdge(6, 7, 27 );
    g.addEdge(8, 7, 6 );
    g.addEdge(7, 9, 10 );
    g.addEdge(9, 8, 11 );
    g.addEdge(8, 10, 15 );
    g.addEdge(9, 11, 12);
    g.addEdge(10, 12, 19 );
    g.addEdge(9, 12, 1 );
    g.addEdge(11, 12, 2 );
    g.addEdge(11, 13, 22 );
    g.addEdge(12, 13, 17 );

    cout << "Maximum flow " << g.DinicMaxflow(0, 5);
    return 0;
}
