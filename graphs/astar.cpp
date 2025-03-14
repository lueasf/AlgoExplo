#include <iostream>
#include <vector>
#include <queue> // priority_queue
#include <cmath> // abs
#include <utility> // pair
#include <unordered_map>

using namespace std;
using Pair = pair<int,int>;

struct Node{
    int x, y;
    double g, h; // g : cost from start, h : heuristic cost
    Node* parent; // pointer to parent node

    Node(int x, int y, double g = 0, double h = 0, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    double f() const{return g + h;}

    // Compare nodes based on f() value
    bool operator<(const Node& other) const{return f() > other.f();}
};

// Manhattan distance heuristic
double heuritic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<Pair> reconstructPath(Node* node){
    vector<Pair> path;
}

// A* algorithm
vector<Pair> aStar(const vector<vector<int>>& grid, Pair start, Pair goal){
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Node, vector<Node>, greater<Node>> openSet; // nodes to be evaluated
    unordered_map<int, unordered_map<int, Node*>> visited; // visited nodes

    


}