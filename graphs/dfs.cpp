#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited){
    visited[node] = true;
    cout << "Visited node " << node << "\n";

    for (int neighbor : graph[node]){
        if (!visited[neighbor]){
            dfs(neighbor, graph, visited);
        }
    }
}

int main(){
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(0);


    /*
        0 <--> 1 <--> 2 <--> 3 --> 4 --> 0
    */

    vector<bool> visited(n, false);
    cout << "DFS starting from node 0\n";
    dfs(0, graph, visited);

}