#pragma once

#include <vector>
#include <list>

using std::vector;

namespace ariel{
    class Graph {
    private:
        vector<vector<int>> m_matrix;
        size_t m_vertices;
        size_t m_edges;
        bool m_has_negative_weight = false;
    public:
        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph();
        [[nodiscard]] const vector<vector<int>>& getAdjMatrix() const;

    };
}




