#include <iostream> 
#include <vector>   // vector
#include <queue> // priority_queue
#include <utility> // pair
#include <climits> // INT_MAX = 2^31 - 1

using namespace std;

using Pair = pair<int, int>;
// Pair.first: node, Pair.second: weight
// ex : Pair p = {10, 3}; p.first = 10 (distance), p.second = 3 (nœud)

// Dijkstra's algorithm
// O((V + E) log V) in time, with V : Vertices, E : Edges
// O(V) in space
void dijkstra(const vector<vector<Pair>>& graph, int start, vector<int>& dist){
    int n = graph.size();
    dist.assign(n, INT_MAX); // Initialize all distances to infinity
    dist[start] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    // <type, container, comparator such as greater or less>
    // greater: min heap (top() = smallest element)

    pq.push({0, start});

    while (!pq.empty()){
        int u = pq.top().second; // node with the smallest distance
        int d = pq.top().first; // distance of u
        pq.pop();

        // Skip if we have already found a better path to u
        if (d > dist[u]) continue; 

        // iterate over all neighbors of u
        for (const auto& edge : graph[u]){ // auto so that the compiler can deduce the type of edge
            int v = edge.first; // neighbor of u
            int w = edge.second; // weight of the edge (u, v)

            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    int n = 5;
    vector<vector<Pair>> graph(n);

    graph[0].push_back({1, 10}); // edge (0, 1) with weight 10
    graph[1].push_back({2, 2}); // edge (1, 2) with weight 2
    graph[0].push_back({2, 5});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});

    int start = 0;
    vector<int> dist(n);
    dijkstra(graph, start, dist);

    cout << "distance from node " << start << " to each node:" << endl;
    for (int i = 0; i < n; i++){
        cout << "node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
