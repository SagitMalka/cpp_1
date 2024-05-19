//
// 209294768 sagitmalka10@gmail.com
//
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;

#include "Graph.hpp"
#include "doctest.h"
#include <vector>

using namespace ariel;
using namespace std;

TEST_CASE("Test isConnected with simple connected graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with simple disconnected graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with single node graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with fully connected graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with large connected graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with large disconnected graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with graph having isolated nodes")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with cycle graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with line graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
}


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test shortestPath with simple graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test shortestPath with disconnected graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "-1");
}

TEST_CASE("Test shortestPath with invalid source or destination")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK_THROWS(Algorithms::shortestPath(g, 0, 5) == "Invalid source or destination");
}

TEST_CASE("Test shortestPath with negative edge weights")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, -1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->2->3");
}


TEST_CASE("Test isContainsCycle with acyclic graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with cyclic graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with self-loop")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with multiple cycles")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with disconnected graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with single node graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite.");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite.");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3, 5}");
}
TEST_CASE("Test isBipartite with non-bipartite graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite.");
}

TEST_CASE("Test isBipartite with single node graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
    
TEST_CASE("Test negativeCycle with graph without negative cycle")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 2, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, -3, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test negativeCycle with graph containing negative cycle")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 2, 0},
        {0, 0, 0, 0},
        {0, 1, 0, -1},
        {0, 0, -3, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == true);
}

TEST_CASE("Test negativeCycle with graph containing negative self-loop")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 2, 0},
        {0, 0, 0, 0},
        {0, 1, -2, 0},
        {0, 0, -3, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == true);
}


TEST_CASE("Test negativeCycle with disconnected graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 2, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test negativeCycle with single node graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test loadGraph with valid square matrix")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK_NOTHROW(g.loadGraph(graph));
}

TEST_CASE("Test loadGraph with valid non-square matrix")
{
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0},
        {0, 0, 0}}; // Non-square matrix
    CHECK_THROWS_AS(g.loadGraph(graph), std::invalid_argument);
}

TEST_CASE("Test loadGraph with empty matrix")
{
    Graph g;
    std::vector<std::vector<int>> graph = {};
    CHECK_THROWS_AS(g.loadGraph(graph), std::invalid_argument);
}

TEST_CASE("Test loadGraph with empty graph")
{
    Graph g;
    std::vector<std::vector<int>> graph = {{}};
    CHECK_THROWS_AS(g.loadGraph(graph), std::invalid_argument);
}
