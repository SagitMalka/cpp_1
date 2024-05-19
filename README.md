# Graph Algorithms

## Overview

This project implements a set of graph-related algorithms and utilities in C++. It includes a Graph class to represent graphs and an Algorithms class that provides various methods to perform common graph algorithms such as checking connectivity, finding the shortest path, detecting if a graph is bipartite, detecting cycles, and detecting negative weight cycles.

## Files
- Graph.hpp / Graph.cpp: Defines the Graph class and its methods.
- Algorithms.hpp / Algorithms.cpp: Defines the Algorithms class and its methods.
- main.cpp: Example usage of the Graph and Algorithms classes.

## Graph Class

The Graph class provides the following functions:
### void loadGraph(const vector<vector<int>>& matrix)
Loads the graph from an adjacency matrix.

### void printGraph()
Prints the adjacency matrix of the graph to the console.

### [[nodiscard]] const vector<vector<int>>& getAdjMatrix() const
Returns the adjacency matrix of the graph.

## Algorithms Class
The Algorithms class provides the following functions:

### static int isConnected(Graph& graph)
Checks if the graph is connected. Returns 1 if connected, 0 otherwise.

### static string shortestPath(const Graph& g, int source, int vertex_v)
Finds the shortest path from the source vertex to the destination vertex vertex_v using the Bellman-Ford algorithm. Returns the path as a string in the format "0->1->2".

### static string isBipartite(const Graph& graph)
Checks if the graph is bipartite. Returns "The graph is bipartite: A={...}, B={...}." if true, where A and B are the sets of the bipartition. Returns "The graph is not bipartite." if false.

### static bool isContainsCycle(const Graph& graph)
Checks if the graph contains a cycle. Returns true if a cycle is found, false otherwise.

### static bool negativeCycle(const Graph& graph)
Checks if the graph contains a negative weight cycle using the Bellman-Ford algorithm. Returns true if a negative weight cycle is found, false otherwise.

## Usage
Here is an example of how to use the Graph and Algorithms classes in your main.cpp file:
```
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

int main() {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 5, 0},
        {0, 0, 6},
        {2, 0, 0}
    };

    try {
        g.loadGraph(graph);
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    g.printGraph();

    std::cout << "Is the graph connected? " << Algorithms::isConnected(g) << std::endl;
    std::cout << "Shortest path from 0 to 2: " << Algorithms::shortestPath(g, 0, 2) << std::endl;
    std::cout << "Is the graph bipartite? " << Algorithms::isBipartite(g) << std::endl;
    std::cout << "Does the graph contain a cycle? " << (Algorithms::isContainsCycle(g) ? "Yes" : "No") << std::endl;
    std::cout << "Does the graph contain a negative weight cycle? " << (Algorithms::negativeCycle(g) ? "Yes" : "No") << std::endl;

    return 0;
}
```
### Building
To build the project with CMakeLists.txt file you can use:
```
cmake_minimum_required(VERSION 3.10)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Graph.cpp Algorithms.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR})

```
## License
This project is licensed under the MIT License.


