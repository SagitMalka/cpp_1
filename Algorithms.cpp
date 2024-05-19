// 
// 209294768 sagitmalka10@gmail.com
//

#include "Algorithms.hpp"
#include <unordered_set>
#include <string>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <stack>

using std::vector;
using std::unordered_set;
using std::string;
using std::ostringstream;
using std::stack;
using std::queue;
using std::unordered_map;
using std::list;
using std::pair;
using std::make_pair;



namespace ariel{




    int ariel::Algorithms::isConnected(ariel::Graph &graph) {
        const vector<vector<int>>& adjMatrix = graph.getAdjMatrix();
        int v_size = (int)graph.getAdjMatrix().size();

        unordered_set<int> visited;

        traverse(0, adjMatrix, visited, v_size);

        return (int)visited.size() == v_size? 1: 0;
    }

    void Algorithms::traverse(int u, const vector<vector<int>> &adjacencyMatrix, unordered_set<int> &visited, int v_size) {
        visited.insert(u);
        
        for (int i = 0; i < v_size; ++i) {
            if (adjacencyMatrix[u][i] && visited.find(i) == visited.end()) {
                traverse(i, adjacencyMatrix, visited, v_size);
            }
        }
    }
    string Algorithms::shortestPath(const Graph& g, int source, int dest) {
        int max_index = (int)g.getAdjMatrix().size() -1;
        if(source > max_index || dest > max_index || source < 0 || dest < 0){
            throw::std::range_error("Invalid source or destination");
        }
        const vector<int>& parents = bellmanFord(g, source);
        if(parents[dest] == std::numeric_limits<int>::max()){
            return "-1";
        }
        ostringstream oss = constructPath(source, dest, parents);

        return oss.str();

    }
    vector<int> Algorithms::bellmanFord(const Graph& graph, int source) {
        const vector<vector<int>>& adjMatrix = graph.getAdjMatrix();
        int num_of_vertices;
        num_of_vertices = adjMatrix.size();
        vector<int> distance(num_of_vertices, std::numeric_limits<int>::max());
        vector<int> parents(num_of_vertices, -1);
        distance[source] = 0;


        // Relax edges repeatedly
        for (int i = 0; i < num_of_vertices - 1; ++i) {
            for (int u = 0; u < num_of_vertices; ++u) {
                for (int v = 0; v < num_of_vertices; ++v) {
                    bool hasEdge = adjMatrix[u][v] != 0;
                    bool hasValidDistance = distance[u] != std::numeric_limits<int>::max();
                    bool hasShorterDistance = distance[u] + adjMatrix[u][v] < distance[v];

                    if (hasEdge &&  hasValidDistance && hasShorterDistance) {
                        distance[v] = distance[u] + adjMatrix[u][v];
                        parents[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < num_of_vertices; ++u) {
            for (int v = 0; v < num_of_vertices; ++v) {
                if (adjMatrix[u][v] != 0 && distance[u] != std::numeric_limits<int>::max() && distance[u] + adjMatrix[u][v] < distance[v]) {
                    throw std::runtime_error("Graph contains a negative cycle");
                }
            }
        }

        return parents;
    }
    ostringstream Algorithms::constructPath(int source, int dest, const vector<int>& parents){
        ostringstream oss;
        stack<int> vertices;

        int curr_vertex = dest;

        while (curr_vertex != source && parents[curr_vertex] != -1) {
            vertices.push(curr_vertex);
            curr_vertex = parents[curr_vertex];
        }
        vertices.push(source);
        if(vertices.size() == 1 && vertices.top() == source) {
            oss << "-1";
            return oss;
        }

        while (!vertices.empty()) {
            if(vertices.size() == 1){
                oss << vertices.top();
                vertices.pop();
            }
            else{
                oss << vertices.top() << "->";
                vertices.pop();
            }
        }


        return oss;
    }
    string Algorithms::ConstructSets(const unordered_set<int>& setA, unordered_set<int> setB) {
        string result = "The graph is bipartite: A={";
        bool first_vertex = true;
        for (int vertex : setA) {
            if(!first_vertex){
                result += ", ";
            }
            result += std::to_string(vertex);
            first_vertex = false;
        }
//        if (!setA.empty()) {
//            result.pop_back(); // Remove the last comma
//        }
        first_vertex = true;
        result += "}, B={";
        for (int vertex : setB) {
            if(!first_vertex){
                result += ", ";
            }
            result += std::to_string(vertex);
            first_vertex = false;
        }
        result += "}";

        return result;
    }
    string Algorithms::isBipartite(const Graph &graph) {
        const vector<vector<int>>& adjacencyMatrix = graph.getAdjMatrix();
        int numVertices;
        numVertices = adjacencyMatrix.size();

        unordered_map<int, string> colorMap;
        unordered_set<int> visited;

        for (int i = 0; i < numVertices; ++i) {
            if (visited.find(i) == visited.end()) {
                std::queue<int> q;
                q.push(i);
                colorMap[i] = "A";
                visited.insert(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < numVertices; ++v) {
                        if (adjacencyMatrix[u][v] != 0) {
                            if (visited.find(v) == visited.end()) {
                                visited.insert(v);
                                q.push(v);
                                colorMap[v] = (colorMap[u] == "A") ? "B" : "A";
                            } else if (colorMap[u] == colorMap[v]) {
                                return "The graph is not bipartite.";
                            }
                        }
                    }
                }
            }
        }

        // Construct sets A and B based on the coloring
        std::unordered_set<int> setA, setB;
        for (const auto& pair : colorMap) {
            if (pair.second == "A") {
                setA.insert(pair.first);
            } else {
                setB.insert(pair.first);
            }
        }

        // Construct the output string
        string result = ConstructSets(setA, setB);

        return result;
    }

    bool Algorithms::isContainsCycle(const Graph &graph) {
        auto adjMatrix = graph.getAdjMatrix();
        stack<pair<int, int>> v_stack;
        v_stack.emplace(0, -1);
        size_t vertices = adjMatrix.size();
        vector<bool> visited(vertices, false);
        vector<int> parents(vertices, -1);
        stack<int> result;

        while (!v_stack.empty()) {
            int v = v_stack.top().first;
            int father = v_stack.top().second;
            v_stack.pop();

            if (!visited[v]) {
                visited[v] = true;
                auto& edges = adjMatrix[v];

                for (int w = 0; w < (int)edges.size(); ++w) {
                    if (edges[w] != 0) {
                        if (!visited[w]) {
                            v_stack.emplace(w, v);
                            parents[w] = v;
                        } else if (w != father) {
                            return true;
//                            result.push(w);
//                            int current = v;
//                            while (current != w) {
//                                result.push(current);
//                                current = parents[current];
//                            }
//                            result.push(w);
//                            //result.push(v); // to complete the cycle
//                            return constructCycle(result).str();
                        }
                    }
                }
            }
        }
        return false;
    }





    ostringstream Algorithms::constructCycle(stack<int> &vertices) {
        ostringstream oss;
        while (!vertices.empty()) {
            if(vertices.size() == 1){
                oss << vertices.top();
                vertices.pop();
            }
            else{
                oss << vertices.top() << "->";
                vertices.pop();
            }
        }


        return oss;
    }

    

    // bool Algorithms::negativeCycle(const Graph& graph){
    //     auto adjMatrix = graph.getAdjMatrix();
    //     stack<pair<int, int>> v_stack;
    //     v_stack.emplace(0, -1);
    //     size_t vertices = adjMatrix.size();
    //     vector<bool> visited(vertices, false);
    //     vector<int> parents(vertices, -1);
    //     stack<int> result;

    //     while (!v_stack.empty()) {
    //         int v = v_stack.top().first;
    //         int father = v_stack.top().second;
    //         v_stack.pop();

    //         if (!visited[v]) {
    //             visited[v] = true;
    //             auto& edges = adjMatrix[v];

    //             for (int w = 0; w < (int)edges.size(); ++w) {
    //                 if (edges[w] != 0) {
    //                     if (!visited[w]) {
    //                         v_stack.emplace(w, v);
    //                         parents[w] = v;
    //                     } else if (w != father) {
    //                         result.push(w);
    //                         int current = v;
    //                         while (current != w) {
    //                            result.push(current);
    //                            current = parents[current];
    //                        }
    //                        result.push(w);
    //                        //result.push(v); 
    //                         int sumEdges = 0;
    //                         while (!result.empty()){
    //                             int x = result.top();
    //                             result.pop();
    //                             if(!result.empty()){
    //                                 int y = result.top();
    //                                 sumEdges += adjMatrix[x][y];
    //                             }
                                
    //                        }
    //                        return sumEdges < 0 ? true : false;
                           
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool Algorithms::negativeCycle(const Graph& graph){
    auto adjMatrix = graph.getAdjMatrix();
    int vertices = (int)adjMatrix.size();
    vector<int> distances(vertices, std::numeric_limits<int>::max());
    distances[0] = 0; // Start vertex
    
    // Relax edges repeatedly
    for (int i = 0; i < vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (int v = 0; v < vertices; ++v) {
                if (adjMatrix[u][v] != 0 && distances[u] != std::numeric_limits<int>::max() && distances[u] + adjMatrix[u][v] < distances[v]) {
                    distances[v] = distances[u] + adjMatrix[u][v];
                }
            }
        }
    }
    
    // Check for negative cycles
    for (int u = 0; u < vertices; ++u) {
        for (int v = 0; v < vertices; ++v) {
            if (adjMatrix[u][v] != 0 && distances[u] != std::numeric_limits<int>::max() && distances[u] + adjMatrix[u][v] < distances[v]) {
                return true; // Negative cycle found
            }
        }
    }
    
    return false; // No negative cycle found
}

}

