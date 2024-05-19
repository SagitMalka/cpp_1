//
// 209294768 sagitmalka10@gmail.com
//

#pragma once

#include <vector>
#include <list>

using std::vector;

namespace ariel{
    class Graph {
    private:
        vector<vector<int>> m_matrix;
    public:
        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph();
        [[nodiscard]] const vector<vector<int>>& getAdjMatrix() const;

    };
}




