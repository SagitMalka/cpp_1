//
// 209294768 sagitmalka10@gmail.com
//

#include "Graph.hpp"
#include <iostream>

using std::cout;
using std::vector;
using std::endl;

namespace ariel{
    void ariel::Graph::loadGraph(const vector<vector<int>> &matrix) {
        if (matrix.size() == 0) {
        throw std::invalid_argument("Invalid graph: The graph is empty.");
    }
        size_t rows = matrix.size();
        for (const auto& row : matrix) {
            if (row.size() != rows) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        this->m_matrix = matrix;
    }

    void Graph::printGraph() {
        size_t vertices = this->m_matrix.size();
        this->m_vertices = vertices;
        size_t edges = 0;
        for (auto & i : this->m_matrix) {
            for (size_t j = 0; j< this->m_matrix.size(); j++) {
                if(i[j] != 0){
                    edges++;
                }
                if(i[j] < 0){
                    this->m_has_negative_weight = true;
                }
            }
        }
        this->m_edges = edges;
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;

    }

    const vector<vector<int>> &Graph::getAdjMatrix() const {
        return m_matrix;
    }

    size_t Graph::getNumberOfVertices() {
        return this->m_vertices;
    }
}

