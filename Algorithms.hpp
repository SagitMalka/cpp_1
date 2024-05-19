//
// 209294768 sagitmalka10@gmail.com
//
#pragma once

#include "Graph.hpp"
#include <unordered_set>
#include <string>
#include <stack>

using std::vector;
using std::unordered_set;
using std::string;
using std::ostringstream;
using std::stack;

namespace ariel{
    class Algorithms {
    private:
        static void traverse(int u, const vector<vector<int>>& adjacencyMatrix, unordered_set<int>& visited, int v_size);
        static vector<int> bellmanFord(const Graph& , int source);
        static ostringstream constructPath(int source, int dest, const std::vector<int>& parents);
        static string ConstructSets(const unordered_set<int>& setA, unordered_set<int> setB);
        static ostringstream constructCycle(stack<int>& vertices);

    public:
        static int isConnected(Graph& graph);
        static string shortestPath(const Graph& g, int source, int vertex_v);
        static string isBipartite(const Graph& graph);
        static bool isContainsCycle(const Graph& graph);
        static bool negativeCycle(const Graph& graph);

    };

}


